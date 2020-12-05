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
	std::vector<sf::Color> pieColors;
	std::vector<mouseOverSlice*> slices;
	sf::Font* font;
	sf::Color darkCol;
	sf::Color midCol;

	//temp map (other part in const)
	std::map<int, std::string, std::greater<int>> hashmap;

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
		auto j = hashmap.begin();
		int k = j->first;
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
			a->value = j->first;
			a->string = j->second;
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
					k = j->first;
					m += 1;
				}
			}
		}
	}

	void sendDrawables(std::vector<sf::Drawable*>* to) {
		to->insert(to->end(), slices.begin(), slices.end());
	}

	pieChart(float rad, float xpos, float ypos, int r, int g, int b, std::vector<sf::Drawable*>* to, sf::Color dark, sf::Color mid, sf::Font* _font) {
		//temp map too
		hashmap.insert(std::pair<int, std::string>(10, "Trump"));
		hashmap.insert(std::pair<int, std::string>(29, "Biden"));
		hashmap.insert(std::pair<int, std::string>(17, "Conservative"));
		hashmap.insert(std::pair<int, std::string>(11, "Democrat"));
		hashmap.insert(std::pair<int, std::string>(8, "Swag Money"));
		hashmap.insert(std::pair<int, std::string>(8, "Swag"));
		hashmap.insert(std::pair<int, std::string>(2, "Ignored"));

		setSize(rad, xpos, ypos);
		setColor(r, g, b);
		font = _font;
		darkCol = dark;
		midCol = mid;
		initSlices();
		sendDrawables(to);
	}

};