#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <unordered_map>
#define PI 3.14159265f

class pieChart {
	 float PIE_R, PIE_X, PIE_Y;
	 int MAX_COLS = 6;
	 std::vector<sf::Color> pieColors;
	 std::vector<sf::ConvexShape*> slices;

	 //temp map (other part in const)
	 std::map<int, std::string, std::greater<int>> hashmap;
	 

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
			auto a = new sf::ConvexShape;
			a->setPointCount(3);
			a->setPoint(0, sf::Vector2f(0, 0));
			a->setPosition(PIE_X, PIE_Y);
			a->setFillColor(sf::Color::Magenta);
			a->setPoint(1, sf::Vector2f((float)(PIE_R*std::sin((2.0f * PI / 100.0f)*i)),
				(float)(-PIE_R * std::cos((2.0f * PI / 100.0f)*i))));
			a->setPoint(2, sf::Vector2f((float)(PIE_R*std::sin((2.0f * PI / 100.0f)*(i + 1))),
				(float)(-PIE_R * std::cos((2.0f * PI / 100.0f)*(i + 1)))));
			//this bit uggo but it assigns colors
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
			//if (k == j->first / 2) { //align onpie text
			//	onPieTexts[m].setPosition(sf::Vector2f((float)(PIE_X + PIE_R * .7 * std::sin((2.0f * PI / 100.0f)*i)),
			//		(float)(PIE_Y - PIE_R * .7 * std::cos((2.0f * PI / 100.0f)*i))));
			//}
		}
	}

	void sendDrawables(std::vector<sf::Drawable*>* to) {
		to->insert(to->end(), slices.begin(), slices.end());
	}

	pieChart(float rad, float xpos, float ypos, int r, int g, int b, std::vector<sf::Drawable*>* to) {
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
		initSlices();
		sendDrawables(to);
	}

};

class GUIHandler {
	sf::RenderWindow window;
	sf::Font fontAHG;
	std::vector<sf::Drawable*> drawables;
	int state = 0; //0 for pie, 1 for bar
	std::vector<sf::Drawable*> pieDrawables;

	const int WIDTH = 1280, HEIGHT = 720;

public:
	GUIHandler() {
		//initialize window
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;
		window.create(sf::VideoMode(WIDTH, HEIGHT), "COP3530 Project 3: Team Cool Team Name", sf::Style::Default, settings);

		//font
		if (!fontAHG.loadFromFile("AlteHaasGroteskBold.ttf")) {
			std::cout << "font not loaded\n";
		}

		//title (make class plz)
		sf::RectangleShape* titlBox = new sf::RectangleShape;
		titlBox->setSize(sf::Vector2f(WIDTH, 90));
		titlBox->setFillColor(sf::Color(57, 50, 50));
		titlBox->setPosition(0, 0);
		drawables.push_back(titlBox);

		sf::Text* title = new sf::Text;
		title->setFont(fontAHG);
		title->setString("The Politicization of the Covid-19 Pandemic on Twitter");
		title->setCharacterSize(40);
		title->setFillColor(sf::Color(243, 239, 231));
		sf::FloatRect titleRect = title->getLocalBounds();
		title->setOrigin(titleRect.width / 2.0f, titleRect.height / 2.0f);
		title->setPosition(WIDTH / 2, 32);
		drawables.push_back(title);

		//pie chart things
		pieChart leftChart(160.0f, WIDTH / 2.0f - 400.0f, HEIGHT / 2.0f - 50.0f, //size
			59, 235, 167, &pieDrawables); //color rgb and draw group
		pieChart midChart(160.0f, WIDTH / 2.0f, HEIGHT / 2.0f - 50.0f, 199, 197, 193, &pieDrawables);
		pieChart rightChart(160.0f, WIDTH / 2.0f + 400.0f, HEIGHT / 2.0f - 50.0f, 234, 12, 44, &pieDrawables);

	}

	~GUIHandler() {
		drawables.clear();
	}

	bool update() {
		//event handling
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				return false;
			}
		}


		//drawing
		window.clear(sf::Color(243, 239, 231));
		for (auto it : drawables) { 
			window.draw(*it);
		}
		if (state == 0) {
			for (auto it : pieDrawables) {
				window.draw(*it);
			}
		}
		
		window.display();

		return true;
	}
};