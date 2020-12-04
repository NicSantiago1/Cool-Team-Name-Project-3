#pragma once

class barChart{
	float xpos, ypos, width, height;
	std::vector<sf::RectangleShape*> bars;
	sf::Color colors[2];

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
		int vals[24];
		for (int i = 0; i < 24; i++) {
			vals[i] = ((i + 56)*(i + 173) % 400);
		}

		float adjwidth = width * 2.0f / 3.0f;

		for (int i = 0; i < size; i++) {
			auto a = new sf::RectangleShape(sf::Vector2f(adjwidth / size, 0 - vals[i]));
			a->setFillColor(colors[(i-1) % 2]);
			a->setPosition(xpos+(adjwidth / size)*(i + (i-1)/2), ypos);
			bars.push_back(a);
		}
	}

	void sendDrawables(std::vector<sf::Drawable*>* to) {
		to->insert(to->end(), bars.begin(), bars.end());
	}

	barChart(float _x, float _y, float _w, float _h, sf::Color l, sf::Color n, sf::Color r, std::vector<sf::Drawable*>* to) {
		setSize(_x,_y,_w,_h);
		setColors(l,n,r);
		initBars();
		sendDrawables(to);
	}
};