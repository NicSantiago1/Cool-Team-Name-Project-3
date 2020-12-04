#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <unordered_map>
#include "pieChart.hpp"
#include "barChart.hpp"

class GUIHandler {
	sf::RenderWindow window;
	sf::Font fontAHG;
	sf::Font fontAHGl;
	
	int state = 0; //0 for pie, 1 for bar
	std::vector<sf::Drawable*> drawables;
	std::vector<sf::Drawable*> pieDrawables;
	std::vector<sf::Drawable*> barDrawables;

	//window size
	const int WIDTH = 1280, HEIGHT = 720;
	//side colors
	int lr =  59, lg = 226, lb = 235;
	int nr = 199, ng = 197, nb = 193;
	int rr = 234, rg =  12, rb =  44;
	//bg colors
	sf::Color darkCol = sf::Color(57, 50, 50);
	sf::Color lightCol = sf::Color(243, 239, 231);
	sf::Color midCol = sf::Color(199, 196, 189);
	
	//charts
	barChart* bChart;
	//mouseover
	sf::Text* mouseover;
	sf::RectangleShape* mouseoverBox;

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
		if (!fontAHGl.loadFromFile("AlteHaasGroteskRegular.ttf")) {
			std::cout << "font not loaded\n";
		}

		//title
		sf::RectangleShape* titlBox = new sf::RectangleShape;
		titlBox->setSize(sf::Vector2f(WIDTH, 90));
		titlBox->setFillColor(midCol);
		titlBox->setPosition(0, 0);
		drawables.push_back(titlBox);

		sf::Text* title = new sf::Text;
		title->setFont(fontAHG);
		title->setString("The Politicization of the Covid-19 Pandemic on Twitter");
		title->setCharacterSize(40);
		title->setFillColor(darkCol);
		sf::FloatRect titleRect = title->getLocalBounds();
		title->setOrigin(titleRect.width / 2.0f, titleRect.height / 2.0f);
		title->setPosition(WIDTH / 2, 32);
		drawables.push_back(title);


		//pie chart things (size, xypos, rgb, draw group
		pieChart leftChart (160.0f, WIDTH / 2.0f - 400.0f, HEIGHT / 2.0f - 50.0f, lr, lg, lb, &pieDrawables, &fontAHG);
		pieChart midChart  (160.0f, WIDTH / 2.0f         , HEIGHT / 2.0f - 50.0f, nr, ng, nb, &pieDrawables, &fontAHG);
		pieChart rightChart(160.0f, WIDTH / 2.0f + 400.0f, HEIGHT / 2.0f - 50.0f, rr, rg, rb, &pieDrawables, &fontAHG);


		//bar chart things
		bChart = new barChart(140, 580, 1000, 400, sf::Color(lr, lg, lb), sf::Color(nr, ng, nb), sf::Color(rr, rg, rb), &barDrawables, darkCol, midCol, &fontAHGl, &fontAHG);
		

		//mouseover
		mouseover = new sf::Text();
		mouseover->setString("");
		mouseover->setFont(fontAHGl);
		mouseover->setFillColor(darkCol);
		mouseover->setCharacterSize(20);
		mouseoverBox = new sf::RectangleShape();
		mouseoverBox->setFillColor(lightCol);
		mouseoverBox->setSize(sf::Vector2f(0, 0));
	}

	~GUIHandler() {
		drawables.clear();
		pieDrawables.clear();
		barDrawables.clear();
		delete bChart;
		delete mouseover, mouseoverBox;
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

		if (state == 0) {
			//pieChart.checkMouseOvers();
		}
		else
			bChart->checkMouseOvers(&window, mouseover, mouseoverBox);


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
		window.draw(*mouseoverBox);
		window.draw(*mouseover);
		
		window.display();

		//return whether still running (ie yes, the false return is earlier)
		return true;
	}
};