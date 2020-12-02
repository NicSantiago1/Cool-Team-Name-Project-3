#pragma once
#include <iostream>

//graphics
#include <SFML/Graphics.hpp>
#include "GUIHandler.hpp"

int main()
{
	GUIHandler GUI;

	bool running = true;
	while (running) {
		running = GUI.update();
	}

	return 0;
}