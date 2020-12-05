#pragma once
#include <iostream>

class mouseOverBar : public sf::RectangleShape {
public:
	int value;
};

class barChart{
	float xpos, ypos, width, height;
	std::vector<mouseOverBar*> bars;
	std::vector<sf::Drawable*> extras;
	sf::Color colors[2];
	sf::Color darkCol;
	sf::Color midCol;
	sf::Font* font, * bFont;
	std::string monthStrs[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

public:
	void setSize(float _x, float _y, float _w, float _h) {
		xpos = _x;
		ypos = _y;
		width = _w;
		height = _h;
	}

	void setColors(sf::Color leftC, sf::Color neutC, sf::Color rightC) {
		colors[0] = leftC;
		//colors[1] = neutC;
		colors[1] = rightC;
	}

	void initBars() {
		//this will have to be changed around later
		int size = 24;
		unsigned int vals[24];
		float maxVal = 0;
		float adjwidth = width * 2.0f / 3.0f;

		vals[0] = 156930/2;
		for (int i = 1; i < 24; i++) {
			vals[i] = (((vals[i-1] + 56)*(vals[i - 1] + 173) % 500000) + 100);
			if (vals[i] > maxVal)
				maxVal = vals[i];
		}

		//create vert bars
		for (int i = 0; i < size; i++) {
			auto a = new mouseOverBar();
			a->setSize(sf::Vector2f(adjwidth / size, 0.0f - (float)vals[i] / maxVal * height));
			a->setFillColor(colors[(i) % 2]);
			a->setPosition(xpos+(adjwidth / size)*(i + (i)/2), ypos);
			a->value = vals[i];
			bars.push_back(a);
		}

		//create horz bars (5-9 in increments of 2*10^n-1 where n is the max vals length
		int scaleSize = maxVal;
		int power = 0;
		while (scaleSize > 10) {
			scaleSize /= 10;
			power++;
		}
		scaleSize = 2 * pow(10, power);
		if (scaleSize >= maxVal)
			scaleSize /= 10;

		int i = 0;
		do {

			if (i % 5 == 0) {
				//text
				std::string tmp = std::to_string(scaleSize*i);
				auto text = new sf::Text(tmp, *font, 20);
				text->setFillColor(darkCol);
				text->setPosition(xpos - 20 - text->getLocalBounds().width, ypos - scaleSize * i / 5 / maxVal * height - 24);
				extras.push_back(text);

				//line
				auto line = new sf::RectangleShape(sf::Vector2f(width + 20.0f - adjwidth / size + text->getLocalBounds().width + 14, 5.0f));
				line->setFillColor(midCol);
				line->setPosition(xpos - 22.0f - text->getLocalBounds().width - 2, ypos - scaleSize * i / 5 / maxVal * height);
				extras.push_back(line);
			}
			else {
				//lil line
				auto line = new sf::RectangleShape(sf::Vector2f(width + 20.0f - adjwidth / size, 2.0f));
				line->setFillColor(midCol);
				line->setPosition(xpos - 10.0f, ypos - scaleSize * i / 5 / maxVal * height);
				extras.push_back(line);
			}
			
			i++;
		} while (scaleSize * i <= maxVal * 5);
	}

	void initText() {
		for (int i = 0; i < 12; i++) {
			auto text = new sf::Text(monthStrs[i],*font, 20);
			text->setFillColor(darkCol);
			text->setPosition(xpos + i*width/12.0f, ypos+10);
			extras.push_back(text);
		}
	}

	void sendDrawables(std::vector<sf::Drawable*>* to) {
		to->insert(to->end(), extras.begin(), extras.end());
		to->insert(to->end(), bars.begin(), bars.end());
	}

	void init() {
		initText();
		initBars();
	}

	void checkMouseOvers(sf::RenderWindow* window, sf::Text* mouseover, sf::RectangleShape* rect) {
		mouseover->setString("");
		rect->setSize(sf::Vector2f(0,0));
		for (auto it : bars) {
			if (it->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window)))) {
				mouseover->setString(std::to_string(it->value));
				sf::Vector2f mousepos = sf::Vector2f(sf::Mouse::getPosition(*window));
				mouseover->setPosition(mousepos.x, mousepos.y - mouseover->getGlobalBounds().height - 10);
				rect->setPosition(sf::Vector2f(mouseover->getGlobalBounds().left-5, mouseover->getGlobalBounds().top - 5));
				rect->setSize(sf::Vector2f(mouseover->getGlobalBounds().width+10, mouseover->getGlobalBounds().height + 10));
				break;
			}
		}
	}

	barChart(float _x, float _y, float _w, float _h, sf::Color l, sf::Color n, sf::Color r, std::vector<sf::Drawable*>* to, sf::Color dark, sf::Color mid, sf::Font* _font, sf::Font* _bFont) {
		setSize(_x,_y,_w,_h);
		setColors(l,n,r);
		darkCol = dark;
		midCol = mid;
		font = _font;
		bFont = _bFont;

		init();
		sendDrawables(to);
	}
};