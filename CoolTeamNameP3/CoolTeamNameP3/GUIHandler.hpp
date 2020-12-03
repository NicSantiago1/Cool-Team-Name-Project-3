#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <unordered_map>
#include "pieChart.hpp"
#include "barChart.hpp"

class GUIHandler {
	sf::RenderWindow window;
	sf::Font fontAHG;
	
	int state = 0; //0 for pie, 1 for bar
	std::vector<sf::Drawable*> drawables;
	std::vector<sf::Drawable*> pieDrawables;
	std::vector<sf::Drawable*> barDrawables;

	//window size
	const int WIDTH = 1280, HEIGHT = 720;
	//side colors
	int lr =  59, lg = 235, lb = 167;
	int nr = 199, ng = 197, nb = 193;
	int rr = 234, rg =  12, rb =  44;
	//bg colors
	sf::Color darkCol = sf::Color(57, 50, 50);
	sf::Color lightCol = sf::Color(243, 239, 231);

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
		titlBox->setSize(sf::Vector2f(WIDTH, 90));
		titlBox->setFillColor(darkCol);
		titlBox->setPosition(0, 0);
		drawables.push_back(titlBox);

		sf::Text* title = new sf::Text;
		title->setFont(fontAHG);
		title->setString("The Politicization of the Covid-19 Pandemic on Twitter");
		title->setCharacterSize(40);
		title->setFillColor(sf::Color(lightCol));
		sf::FloatRect titleRect = title->getLocalBounds();
		title->setOrigin(titleRect.width / 2.0f, titleRect.height / 2.0f);
		title->setPosition(WIDTH / 2, 32);
		drawables.push_back(title);


		//pie chart things (size, xypos, rgb, draw group
		pieChart leftChart (160.0f, WIDTH / 2.0f - 400.0f, HEIGHT / 2.0f - 50.0f, lr, lg, lb, &pieDrawables);
		pieChart midChart  (160.0f, WIDTH / 2.0f         , HEIGHT / 2.0f - 50.0f, nr, ng, nb, &pieDrawables);
		pieChart rightChart(160.0f, WIDTH / 2.0f + 400.0f, HEIGHT / 2.0f - 50.0f, rr, rg, rb, &pieDrawables);


		//bar chart things
		barChart chart(140, 600, 1000, 500, sf::Color(lr, lg, lb), sf::Color(nr, ng, nb), sf::Color(rr, rg, rb), &barDrawables);
		
	}

	~GUIHandler() {
		drawables.clear();
	}

	bool update() {
		//event handling
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
					
				case sf::Event::Closed: //close window
					window.close();
					return false;
					break;
			
				case sf::Event::KeyPressed: //buttons (temp)
					if (event.key.code == sf::Keyboard::X)
						state = 1;
					if (event.key.code == sf::Keyboard::Z)
						state = 0;
					break;
			}
		}


		//drawing
		window.clear(lightCol);

		for (auto it : drawables)
			window.draw(*it);

		if (state == 0) {
			for (auto it : pieDrawables) {
				window.draw(*it);
			}
		}
		else {
			for (auto it : barDrawables) {
				window.draw(*it);
			}
		}
		
		window.display();

		//return whether still running (ie yes, the false return is earlier)
		return true;
	}
};