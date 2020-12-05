#pragma once
#include <iostream>

//maps
#include "DandA3 Map.hpp"

//graphics
#include <SFML/Graphics.hpp>
#include "GUIHandler.hpp"

int main()
{
	datasetMap yearDataset;
	yearDataset.AddDatasetValues();
	map<pair<string, string>, vector<TweetData>>* mapDS = yearDataset.returnContents();

	vector<int> kwf = yearDataset.returnKeywordFreq();
	GUIHandler GUI(&kwf);

	
	while (GUI.update()) {}

	return 0;
}
