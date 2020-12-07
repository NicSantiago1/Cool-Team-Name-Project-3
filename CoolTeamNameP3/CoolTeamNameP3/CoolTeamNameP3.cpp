#pragma once
#include <iostream>

//ds
#include "DandA3 Map.hpp"
#include "MaxHeap.cpp"

//graphics
#include <SFML/Graphics.hpp>
#include "GUIHandler.hpp"

int main()
{
	datasetMap yearDataset;
	yearDataset.AddDatasetValues();
	map<pair<string, string>, vector<TweetData>>* mapDS = yearDataset.returnContents();
	vector<int> kwf = yearDataset.returnKeywordFreq();

	datasetMaxHeap mHeap(mapDS);
	vector<vector<intNodePair>>* LeftHeaps = new vector<vector<intNodePair>>;
	mHeap.returnLeftHeaps(LeftHeaps);
	vector<vector<intNodePair>>* RightHeaps = new vector<vector<intNodePair>>;
	mHeap.returnRightHeaps(RightHeaps);

	GUIHandler GUI(&kwf, LeftHeaps, RightHeaps);
	
	while (GUI.update()) {}

	delete LeftHeaps;
	delete RightHeaps;
	return 0;
}
