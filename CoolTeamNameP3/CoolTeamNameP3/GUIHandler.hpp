#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class GUIHandler {
	sf::RenderWindow window;
	std::vector<sf::Drawable*> drawables;

public:
	GUIHandler() {
		//sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
		window.create(sf::VideoMode(500, 500), "title");

		sf::CircleShape* shape = new sf::CircleShape(100.f);
		shape->setFillColor(sf::Color::Green);
		drawables.push_back(shape);
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
		window.clear();
		for (int i = 0; i < drawables.size(); i++) {
			window.draw(*drawables[i]);
		}
		window.display();

		return true;
	}
};