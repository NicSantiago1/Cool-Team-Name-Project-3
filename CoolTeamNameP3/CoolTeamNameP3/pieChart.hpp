#pragma once
#define PI 3.14159265f

class mouseOverSlice : public sf::ConvexShape {
public:
	int value;
	std::string string;
};

class pieChart {
	float PIE_R, PIE_X, PIE_Y;
	int MAX_COLS = 6;
	vector<string> pieKeys;
	std::vector<sf::Color> pieColors;
public:
	std::vector<mouseOverSlice*> slices;
	std::vector<sf::Drawable*> extras;
private:
	sf::Font* font;
	sf::Color darkCol;
	sf::Color lightCol;
	int reversed = 1;

	//temp map (other part in const)
	vector<intNodePair>* dataheap;

	std::string intStr(int in) {
		std::string out = std::to_string(in);
		int i = out.length() - 3;
		while (i > 0) {
			out.insert(i, ",");
			i -= 3;
		}
		return out;
	}


public:
	void setSize(float rad, float xpos, float ypos) {
		PIE_R = rad;
		PIE_X = xpos;
		PIE_Y = ypos;
	}

	void setColor(int _r, int _g, int _b) {
		for (int i = 0; i < MAX_COLS; i++) {
			sf::Color tempC;
			tempC.r = _r - (_r / MAX_COLS)*i;
			tempC.g = _g - (_g / MAX_COLS)*i;
			tempC.b = _b - (_b / MAX_COLS)*i;
			pieColors.push_back(tempC);
		}
	}

	void initSlices() {
		//text
		float total = 0;
		auto j = dataheap->begin();
		for (int i = 0; i < MAX_COLS; i++) { //can break if array very small but shouldnt
			pieKeys.push_back(j->contPair.second.keyword);
			total += j->contPair.first;
			j++;
		}
		//side  and onPie text
		vector<sf::Text*> onPieTexts;
		
		int percOther = 100;
		j = dataheap->begin();
		for (int i = 0; i < MAX_COLS - 1; i++) {
			//side
			auto b = new sf::Text;
			b->setFont(*font);
			b->setCharacterSize(20);
			(reversed > 0) ? b->setString(intStr(j->contPair.first * 100 / total) + "% " + j->contPair.second.keyword) : b->setString(j->contPair.second.keyword + " " + intStr(j->contPair.first* 100 / total) + "%");
			percOther -= j->contPair.first / total;
			b->setFillColor(pieColors[i]);
			b->setPosition(PIE_X + (PIE_R + 20) * reversed, PIE_Y - PIE_R + i * 20);
			(reversed > 0) ? b->setOrigin(0, 0) : b->setOrigin(b->getGlobalBounds().width, 0);
			extras.push_back(b);

			//onpie
			b = new sf::Text;
			b->setFont(*font);
			b->setCharacterSize(20);
			b->setString((j->contPair.second.keyword.size() > 5) ? j->contPair.second.keyword.substr(0,4) + "." : j->contPair.second.keyword);
			b->setFillColor(lightCol);
			sf::FloatRect bRect = b->getLocalBounds();
			b->setOrigin(bRect.width / 2.0f, bRect.height / 2.0f);
			onPieTexts.push_back(b);
			j++;
		}
		//"other"
		auto b = new sf::Text;
		b->setFont(*font);
		b->setCharacterSize(20);
		(reversed > 0) ? b->setString(intStr(percOther) + "% " + "Other/None") : b->setString("Other/None " + intStr(percOther) + "%");
		b->setFillColor(pieColors[MAX_COLS - 1]);
		(reversed > 0) ? b->setOrigin(0, 0) : b->setOrigin(b->getGlobalBounds().width, 0);
		b->setPosition(PIE_X + (PIE_R + 20) * reversed, PIE_Y - PIE_R + (MAX_COLS - 1) * 20);
		extras.push_back(b);


		//pie
		j = dataheap->begin();
		int k = j->contPair.first;
		int m = 0;
		for (int i = 0; i < 100; i++) {
			auto a = new mouseOverSlice;
			a->setPointCount(3);
			a->setPoint(0, sf::Vector2f(0, 0));
			a->setPosition(PIE_X, PIE_Y);
			a->setFillColor(sf::Color::Magenta);
			a->setPoint(1, sf::Vector2f((float)(PIE_R*std::sin((2.0f * PI / 100.0f)*i)),
				(float)(-PIE_R * std::cos((2.0f * PI / 100.0f)*i))));
			a->setPoint(2, sf::Vector2f((float)(PIE_R*std::sin((2.0f * PI / 100.0f)*(i + 1))),
				(float)(-PIE_R * std::cos((2.0f * PI / 100.0f)*(i + 1)))));
			//value
			a->value = j->contPair.first;
			a->string = j->contPair.second.keyword;
			//this bit uggo but it assigns colors/text
			a->setFillColor(pieColors[m]);
			slices.push_back(a);
			k--;
			if (k == 0) {
				if (m == MAX_COLS - 2) {
					m++;
					k = 100;
				}
				else {
					j++;
					k = j->contPair.first * 100 / total;
					m += 1;
				}
			}
			if (k == j->contPair.first* 100 / total / 2) { //align onpie text
				onPieTexts[m]->setPosition(sf::Vector2f((float)(PIE_X + PIE_R * .7 * std::sin((2.0f * PI / 100.0f)*i)),
					(float)(PIE_Y - PIE_R * .7 * std::cos((2.0f * PI / 100.0f)*i))));
			}
		}
		extras.insert(extras.end(), onPieTexts.begin(), onPieTexts.end());
	}


	pieChart(float rad, float xpos, float ypos, int r, int g, int b, sf::Color dark, sf::Color light, sf::Font* _font, int _rev, vector<intNodePair>* heap) {
		dataheap = heap;

		setSize(rad, xpos, ypos);
		setColor(r, g, b);
		font = _font;
		darkCol = dark;
		lightCol = light;
		reversed = _rev;
		initSlices();
	}

};