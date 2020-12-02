#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#define PI 3.14159265f

class GUIHandler {
	sf::RenderWindow window;
	sf::Font fontAHG;
	std::vector<sf::Drawable*> drawables;
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


		//title
		sf::RectangleShape* titlBox = new sf::RectangleShape;
		titlBox->setSize(sf::Vector2f(WIDTH, 100));
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


		//temp pie chart map, ik itll be differnet in final but just for now
		std::map<int, std::string, std::greater<int>> hashmap;
		hashmap.insert(std::pair<int, std::string>(10, "Trump"));
		hashmap.insert(std::pair<int, std::string>(29, "Biden"));
		hashmap.insert(std::pair<int, std::string>(17, "Conservative"));
		hashmap.insert(std::pair<int, std::string>(11, "Democrat"));
		hashmap.insert(std::pair<int, std::string>(8, "Swag Money"));
		hashmap.insert(std::pair<int, std::string>(8, "Swag"));
		hashmap.insert(std::pair<int, std::string>(2, "Ignored"));

		//pie chart things
		const float PIE_R = 260.0f, PIE_X = WIDTH / 2 - 330, PIE_Y = HEIGHT / 2 + 50;
		const int MAX_COLS = 6;
		sf::Color pieColors[MAX_COLS]; //= { sf::Color(234,12,44), sf::Color::Green, sf::Color::Magenta,
								//		 sf::Color::Red, sf::Color::Cyan, sf::Color::Black };
		for (int i = 0; i < MAX_COLS; i++) {
			pieColors[i].r = 234 - (234 / MAX_COLS)*i;
			pieColors[i].g = 12 - (12 / MAX_COLS)*i;
			pieColors[i].b = 44 - (44 / MAX_COLS)*i;
		}
		

		std::vector<sf::ConvexShape*> slices;
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
		drawables.insert(drawables.end(), slices.begin(), slices.end());
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
		window.display();

		return true;
	}
};