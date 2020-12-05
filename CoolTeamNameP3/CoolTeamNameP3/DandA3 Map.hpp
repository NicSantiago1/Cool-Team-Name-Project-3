#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class TweetData {
public:
	string ID;
	string tweetContent;
	string hashtags;

	// Two vector containing our selected keywords
	vector<string> rightKeywords{ "example" };
	vector<string> leftKeywords{ "example" };
	int rightKeywordFrequency;
	int leftKeywordFrequency;
	void FindKeywordFrequency() {
		/*
		Two vectors, one containing left keywords and one containing right keywords stored in the TweetData object
		Search the "tweetContent" string and add 1
		*/

		for (int i = 0; i < rightKeywords.size(); i++) {
			if (tweetContent.find(rightKeywords[i]) != string::npos) {
				rightKeywordFrequency++;
			}
		}
		for (int i = 0; i < leftKeywords.size(); i++) {
			if (tweetContent.find(leftKeywords[i]) != string::npos) {
				leftKeywordFrequency++;
			}
		}
	}
};

class datasetMap {
public:
	void AddDatasetValues() {
		string tempDate, tempMonth;

		fstream s;
		s.open("full_dataset_reduced3.tsv", ios::in);

		string datasetRow;
		string partOfRow;

		string ID, date, tweetContent, hashtags;

		int i = 0;
		while (getline(s, datasetRow, '\t')) {
			i++;
			cout << i << endl;
			TweetData tempTw;
			tempTw.ID = datasetRow.substr(1, datasetRow.length() - 2);

			getline(s, datasetRow, '\t');
			tempDate = datasetRow.substr(1, datasetRow.length() - 2);
			tempMonth = datasetRow.substr(5, 3);

			getline(s, datasetRow, '\t');
			tempTw.tweetContent = datasetRow.substr(1, datasetRow.length() - 2);
			tempTw.FindKeywordFrequency();

			getline(s, datasetRow, '\n');
			tempTw.hashtags = datasetRow.substr(1, datasetRow.length() - 2);

			datasetContents[make_pair(tempDate, tempMonth)].push_back(tempTw);
		}

		//temp print func
		//for (auto it : datasetContents) {
		//	std::cout << it.first.first << " " << it.first.second << " " << it.second.at(0).ID << " " << it.second.at(0).tweetContent << " " << it.second.at(0).hashtags << "\n";
		//}
	}
	
	map<pair<string, string>, vector<TweetData>> returnContents() {
		return datasetContents;
	}
private:
	// A vector in case two tweets were published at the same time
	map<pair<string, string>, vector<TweetData>> datasetContents;
};