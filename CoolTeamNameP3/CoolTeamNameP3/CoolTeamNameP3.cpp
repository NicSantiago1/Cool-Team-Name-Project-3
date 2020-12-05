#pragma once
#include <iostream>
#include "DandA3 Map.hpp"

//graphics
#include <SFML/Graphics.hpp>
#include "GUIHandler.hpp"

int main()
{
	GUIHandler GUI;

	datasetMap yearDataset;
	yearDataset.AddDatasetValues();

	while (GUI.update()) {
	}

	return 0;
}
