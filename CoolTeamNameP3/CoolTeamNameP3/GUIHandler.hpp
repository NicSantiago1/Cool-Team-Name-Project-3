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
	
	int state = 0; //0 for bar, 1 to 12 for pie
	std::vector<sf::Drawable*> drawables;
	std::vector<sf::Drawable*> barDrawables;
	std::vector<sf::Drawable*> pieDrawables1;
	std::vector<sf::Drawable*> pieDrawables2;
	std::vector<sf::Drawable*> pieDrawables3;
	std::vector<sf::Drawable*> pieDrawables4;
	std::vector<sf::Drawable*> pieDrawables5;
	std::vector<sf::Drawable*> pieDrawables6;
	std::vector<sf::Drawable*> pieDrawables7;
	std::vector<sf::Drawable*> pieDrawables8;
	std::vector<sf::Drawable*> pieDrawables9;
	std::vector<sf::Drawable*> pieDrawables10;
	std::vector<sf::Drawable*> pieDrawables11;
	std::vector<sf::Drawable*> pieDrawables12;

	//window size
	const int WIDTH = 1280, HEIGHT = 720;
	//side colors
	int lr =  19, lg = 165, lb = 214;
	int nr = 199, ng = 197, nb = 193;
	int rr = 234, rg =  12, rb =  44;
	//bg colors
	sf::Color darkCol = sf::Color(57, 50, 50);
	sf::Color lightCol = sf::Color(243, 239, 231);
	sf::Color midCol = sf::Color(199, 196, 189);
	
	//charts
	vector<pieChart*> leftChart, rightChart;
	int piestate = 0;
	barChart* bChart;
	//mouseover
	sf::Text* mouseover;
	sf::RectangleShape* mouseoverBox;

public:
	GUIHandler(vector<int>* kfreq, vector<vector<intNodePair>>* leftHeaps, vector<vector<intNodePair>>* rightHeaps) {
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


		//pie chart things (yes this is braindead but i really did try to get a vector to work
		//1
			auto temp = new pieChart(160.0f, WIDTH / 2.0f - 400.0f, HEIGHT / 2.0f - 50.0f, lr, lg, lb, darkCol, lightCol, &fontAHGl, 1, &(leftHeaps->at(0)));
			pieDrawables1.insert(pieDrawables1.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables1.insert(pieDrawables1.end(), temp->extras.begin(), temp->extras.end());
			leftChart.push_back(temp);

			temp = new pieChart(160.0f, WIDTH / 2.0f + 400.0f, HEIGHT / 2.0f - 50.0f, rr, rg, rb, darkCol, lightCol, &fontAHGl, -1, &(rightHeaps->at(0)));
			pieDrawables1.insert(pieDrawables1.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables1.insert(pieDrawables1.end(), temp->extras.begin(), temp->extras.end());
			rightChart.push_back(temp);


			temp = new pieChart(160.0f, WIDTH / 2.0f - 400.0f, HEIGHT / 2.0f - 50.0f, lr, lg, lb, darkCol, lightCol, &fontAHGl, 1, &(leftHeaps->at(1)));
			pieDrawables2.insert(pieDrawables2.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables2.insert(pieDrawables2.end(), temp->extras.begin(), temp->extras.end());
			leftChart.push_back(temp);

			temp = new pieChart(160.0f, WIDTH / 2.0f + 400.0f, HEIGHT / 2.0f - 50.0f, rr, rg, rb, darkCol, lightCol, &fontAHGl, -1, &(rightHeaps->at(1)));
			pieDrawables2.insert(pieDrawables2.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables2.insert(pieDrawables2.end(), temp->extras.begin(), temp->extras.end());
			rightChart.push_back(temp);


			temp = new pieChart(160.0f, WIDTH / 2.0f - 400.0f, HEIGHT / 2.0f - 50.0f, lr, lg, lb, darkCol, lightCol, &fontAHGl, 1, &(leftHeaps->at(2)));
			pieDrawables3.insert(pieDrawables3.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables3.insert(pieDrawables3.end(), temp->extras.begin(), temp->extras.end());
			leftChart.push_back(temp);

			temp = new pieChart(160.0f, WIDTH / 2.0f + 400.0f, HEIGHT / 2.0f - 50.0f, rr, rg, rb, darkCol, lightCol, &fontAHGl, -1, &(rightHeaps->at(2)));
			pieDrawables3.insert(pieDrawables3.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables3.insert(pieDrawables3.end(), temp->extras.begin(), temp->extras.end());
			rightChart.push_back(temp);


			temp = new pieChart(160.0f, WIDTH / 2.0f - 400.0f, HEIGHT / 2.0f - 50.0f, lr, lg, lb, darkCol, lightCol, &fontAHGl, 1, &(leftHeaps->at(3)));
			pieDrawables4.insert(pieDrawables4.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables4.insert(pieDrawables4.end(), temp->extras.begin(), temp->extras.end());
			leftChart.push_back(temp);

			temp = new pieChart(160.0f, WIDTH / 2.0f + 400.0f, HEIGHT / 2.0f - 50.0f, rr, rg, rb, darkCol, lightCol, &fontAHGl, -1, &(rightHeaps->at(3)));
			pieDrawables4.insert(pieDrawables4.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables4.insert(pieDrawables4.end(), temp->extras.begin(), temp->extras.end());
			rightChart.push_back(temp);


			temp = new pieChart(160.0f, WIDTH / 2.0f - 400.0f, HEIGHT / 2.0f - 50.0f, lr, lg, lb, darkCol, lightCol, &fontAHGl, 1, &(leftHeaps->at(4)));
			pieDrawables5.insert(pieDrawables5.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables5.insert(pieDrawables5.end(), temp->extras.begin(), temp->extras.end());
			leftChart.push_back(temp);

			temp = new pieChart(160.0f, WIDTH / 2.0f + 400.0f, HEIGHT / 2.0f - 50.0f, rr, rg, rb, darkCol, lightCol, &fontAHGl, -1, &(rightHeaps->at(4)));
			pieDrawables5.insert(pieDrawables5.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables5.insert(pieDrawables5.end(), temp->extras.begin(), temp->extras.end());
			rightChart.push_back(temp);


			temp = new pieChart(160.0f, WIDTH / 2.0f - 400.0f, HEIGHT / 2.0f - 50.0f, lr, lg, lb, darkCol, lightCol, &fontAHGl, 1, &(leftHeaps->at(5)));
			pieDrawables6.insert(pieDrawables6.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables6.insert(pieDrawables6.end(), temp->extras.begin(), temp->extras.end());
			leftChart.push_back(temp);

			temp = new pieChart(160.0f, WIDTH / 2.0f + 400.0f, HEIGHT / 2.0f - 50.0f, rr, rg, rb, darkCol, lightCol, &fontAHGl, -1, &(rightHeaps->at(5)));
			pieDrawables6.insert(pieDrawables6.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables6.insert(pieDrawables6.end(), temp->extras.begin(), temp->extras.end());
			rightChart.push_back(temp);


			temp = new pieChart(160.0f, WIDTH / 2.0f - 400.0f, HEIGHT / 2.0f - 50.0f, lr, lg, lb, darkCol, lightCol, &fontAHGl, 1, &(leftHeaps->at(6)));
			pieDrawables7.insert(pieDrawables7.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables7.insert(pieDrawables7.end(), temp->extras.begin(), temp->extras.end());
			leftChart.push_back(temp);

			temp = new pieChart(160.0f, WIDTH / 2.0f + 400.0f, HEIGHT / 2.0f - 50.0f, rr, rg, rb, darkCol, lightCol, &fontAHGl, -1, &(rightHeaps->at(6)));
			pieDrawables7.insert(pieDrawables7.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables7.insert(pieDrawables7.end(), temp->extras.begin(), temp->extras.end());
			rightChart.push_back(temp);


			temp = new pieChart(160.0f, WIDTH / 2.0f - 400.0f, HEIGHT / 2.0f - 50.0f, lr, lg, lb, darkCol, lightCol, &fontAHGl, 1, &(leftHeaps->at(7)));
			pieDrawables8.insert(pieDrawables8.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables8.insert(pieDrawables8.end(), temp->extras.begin(), temp->extras.end());
			leftChart.push_back(temp);

			temp = new pieChart(160.0f, WIDTH / 2.0f + 400.0f, HEIGHT / 2.0f - 50.0f, rr, rg, rb, darkCol, lightCol, &fontAHGl, -1, &(rightHeaps->at(7)));
			pieDrawables8.insert(pieDrawables8.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables8.insert(pieDrawables8.end(), temp->extras.begin(), temp->extras.end());
			rightChart.push_back(temp);


			temp = new pieChart(160.0f, WIDTH / 2.0f - 400.0f, HEIGHT / 2.0f - 50.0f, lr, lg, lb, darkCol, lightCol, &fontAHGl, 1, &(leftHeaps->at(8)));
			pieDrawables9.insert(pieDrawables9.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables9.insert(pieDrawables9.end(), temp->extras.begin(), temp->extras.end());
			leftChart.push_back(temp);

			temp = new pieChart(160.0f, WIDTH / 2.0f + 400.0f, HEIGHT / 2.0f - 50.0f, rr, rg, rb, darkCol, lightCol, &fontAHGl, -1, &(rightHeaps->at(8)));
			pieDrawables9.insert(pieDrawables9.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables9.insert(pieDrawables9.end(), temp->extras.begin(), temp->extras.end());
			rightChart.push_back(temp);


			temp = new pieChart(160.0f, WIDTH / 2.0f - 400.0f, HEIGHT / 2.0f - 50.0f, lr, lg, lb, darkCol, lightCol, &fontAHGl, 1, &(leftHeaps->at(9)));
			pieDrawables10.insert(pieDrawables10.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables10.insert(pieDrawables10.end(), temp->extras.begin(), temp->extras.end());
			leftChart.push_back(temp);

			temp = new pieChart(160.0f, WIDTH / 2.0f + 400.0f, HEIGHT / 2.0f - 50.0f, rr, rg, rb, darkCol, lightCol, &fontAHGl, -1, &(rightHeaps->at(9)));
			pieDrawables10.insert(pieDrawables10.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables10.insert(pieDrawables10.end(), temp->extras.begin(), temp->extras.end());
			rightChart.push_back(temp);


			temp = new pieChart(160.0f, WIDTH / 2.0f - 400.0f, HEIGHT / 2.0f - 50.0f, lr, lg, lb, darkCol, lightCol, &fontAHGl, 1, &(leftHeaps->at(10)));
			pieDrawables11.insert(pieDrawables11.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables11.insert(pieDrawables11.end(), temp->extras.begin(), temp->extras.end());
			leftChart.push_back(temp);

			temp = new pieChart(160.0f, WIDTH / 2.0f + 400.0f, HEIGHT / 2.0f - 50.0f, rr, rg, rb, darkCol, lightCol, &fontAHGl, -1, &(rightHeaps->at(10)));
			pieDrawables11.insert(pieDrawables11.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables11.insert(pieDrawables11.end(), temp->extras.begin(), temp->extras.end());
			rightChart.push_back(temp);


			temp = new pieChart(160.0f, WIDTH / 2.0f - 400.0f, HEIGHT / 2.0f - 50.0f, lr, lg, lb, darkCol, lightCol, &fontAHGl, 1, &(leftHeaps->at(11)));
			pieDrawables12.insert(pieDrawables12.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables12.insert(pieDrawables12.end(), temp->extras.begin(), temp->extras.end());
			leftChart.push_back(temp);

			temp = new pieChart(160.0f, WIDTH / 2.0f + 400.0f, HEIGHT / 2.0f - 50.0f, rr, rg, rb, darkCol, lightCol, &fontAHGl, -1, &(rightHeaps->at(11)));
			pieDrawables12.insert(pieDrawables12.end(), temp->slices.begin(), temp->slices.end());
			pieDrawables12.insert(pieDrawables12.end(), temp->extras.begin(), temp->extras.end());
			rightChart.push_back(temp);

		//bar chart things
		bChart = new barChart(140, 580, 900, 400, sf::Color(lr, lg, lb), sf::Color(nr, ng, nb), sf::Color(rr, rg, rb), &barDrawables, darkCol, midCol, &fontAHGl, &fontAHG, kfreq);
		

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
		pieDrawables1.clear();
		pieDrawables2.clear();
		pieDrawables3.clear();
		pieDrawables4.clear();
		pieDrawables5.clear();
		pieDrawables6.clear();
		pieDrawables7.clear();
		pieDrawables8.clear();
		pieDrawables9.clear();
		pieDrawables10.clear();
		pieDrawables11.clear();
		pieDrawables12.clear();
		barDrawables.clear();
		delete bChart, leftChart, rightChart;
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
					if (event.key.code == sf::Keyboard::Tilde)
						state = 0;
					if (event.key.code == sf::Keyboard::Num1)
						state = 1;
					if (event.key.code == sf::Keyboard::Num2)
						state = 2;
					if (event.key.code == sf::Keyboard::Num3)
						state = 3;
					if (event.key.code == sf::Keyboard::Num4)
						state = 4;
					if (event.key.code == sf::Keyboard::Num5)
						state = 5;
					if (event.key.code == sf::Keyboard::Num6)
						state = 6;
					if (event.key.code == sf::Keyboard::Num7)
						state = 7;
					if (event.key.code == sf::Keyboard::Num8)
						state = 8;
					if (event.key.code == sf::Keyboard::Num9)
						state = 9;
					if (event.key.code == sf::Keyboard::Num0)
						state = 10;
					if (event.key.code == sf::Keyboard::O)
						state = 11;
					if (event.key.code == sf::Keyboard::P)
						state = 12;
					break;
			}
		}


		//mouseover draw
		mouseover->setString("");
		mouseoverBox->setSize(sf::Vector2f(0, 0));
		if (state == 0) {
			bChart->checkMouseOvers(&window, mouseover, mouseoverBox);
		}

		//drawing
		window.clear(lightCol);

		switch (state) {
		case 0:
			for (auto it : barDrawables)
				window.draw(*it);
			break;
		case 1:
			for (auto it : pieDrawables1)
				window.draw(*it);
			break;
		case 2:
			for (auto it : pieDrawables2)
				window.draw(*it);
			break;
		case 3:
			for (auto it : pieDrawables3)
				window.draw(*it);
			break;
		case 4:
			for (auto it : pieDrawables4)
				window.draw(*it);
			break;
		case 5:
			for (auto it : pieDrawables5)
				window.draw(*it);
			break;
		case 6:
			for (auto it : pieDrawables6)
				window.draw(*it);
			break;
		case 7:
			for (auto it : pieDrawables7)
				window.draw(*it);
			break;
		case 8:
			for (auto it : pieDrawables8)
				window.draw(*it);
			break;
		case 9:
			for (auto it : pieDrawables9)
				window.draw(*it);
			break;
		case 10:
			for (auto it : pieDrawables10)
				window.draw(*it);
			break;
		case 11:
			for (auto it : pieDrawables11)
				window.draw(*it);
			break;
		case 12:
			for (auto it : pieDrawables12)
				window.draw(*it);
			break;
		}

		window.draw(*mouseoverBox);
		window.draw(*mouseover);

		for (auto it : drawables)
			window.draw(*it);

		window.display();

		//return whether still running (ie yes, the false return is earlier)
		return true;
	}
};