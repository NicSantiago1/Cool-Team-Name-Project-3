#pragma once
#include <iostream>

//graphics
#include <SFML/Graphics.hpp>
#include "GUIHandler.hpp"

int main()
{
	GUIHandler GUI;

	while (GUI.update()) {
	}

	return 0;
}
