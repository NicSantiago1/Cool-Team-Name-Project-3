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
};

class datasetMap {
	// Two vector containing our selected keywords
	vector<string> leftKeywords;
	vector<string> rightKeywords;
	vector<int> KeywordFrequency;
	map<pair<string, string>, vector<TweetData>> datasetContents;

	std::string monthStrs[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	int monthIndex(string mnth) {
		for (int i = 0; i < 12; i++) {
			if (!mnth.compare(monthStrs[i]))
				return i;
		}
		return -1;
	}

	string strLower(string in) {
		string out = "";
		for (int i = 0; i < in.length(); i++) {
			out += tolower(in.at(i));
		}
		return out;
	}

	void FindKeywordFrequency(TweetData* tweet, string monthstr) {
		for (int i = 0; i < leftKeywords.size(); i++) {
			if (strLower(tweet->tweetContent).find(leftKeywords[i]) != string::npos) {
				KeywordFrequency.at(0 + monthIndex(monthstr) * 2)++;
			}
		}
		for (int i = 0; i < rightKeywords.size(); i++) {
			if (strLower(tweet->tweetContent).find(rightKeywords[i]) != string::npos) {
				KeywordFrequency.at(1 + monthIndex(monthstr) * 2)++;
			}
		}
	}
public:
	void AddDatasetValues() {
		//init left/right keywords
		string tempS;
		fstream l;
		l.open("Leftist Keywords", ios::in);
		while (getline(l, tempS))
			leftKeywords.push_back(tempS);
		l.close();

		fstream r;
		r.open("Rightist Keywords", ios::in);
		while (getline(r, tempS))
			rightKeywords.push_back(tempS);
		r.close();


		//data
		int skip = 1;
		string tempDate, tempMonth;
		fstream s;
		string datasetRow;
		for (int i = 0; i < 24; i++)
			KeywordFrequency.push_back(1);

		s.open("full_dataset_reduced3_div100.tsv", ios::in);
		int i = 0;
		while (getline(s, datasetRow, '\t')) {
			i++;
			if (i % skip != 0) {
				getline(s, datasetRow, '\n');
				continue;
			}
			TweetData tempTw;
			tempTw.ID = datasetRow.substr(1, datasetRow.length() - 2);

			getline(s, datasetRow, '\t');
			//cout << datasetRow << " ";
			tempDate = datasetRow.substr(1, datasetRow.length() - 2);
			tempMonth = datasetRow.substr(5, 3);

			getline(s, datasetRow, '\t');
			//cout << datasetRow << " ";
			tempTw.tweetContent = datasetRow.substr(1, datasetRow.length() - 2);

			getline(s, datasetRow, '\n');
			//cout << datasetRow << endl;
			tempTw.hashtags = datasetRow.substr(1, datasetRow.length() - 2);

			FindKeywordFrequency(&tempTw, tempMonth);

			datasetContents[make_pair(tempDate, tempMonth)].push_back(tempTw);
		}
		s.close();

		s.open("full_dataset_all_reduced.tsv", ios::in);
		i = 0;
		while (getline(s, datasetRow, '\t')) {
			i++;
			if (i % skip != 0) {
				getline(s, datasetRow, '\n');
				continue;
			}
			TweetData tempTw;
			tempTw.ID = datasetRow.substr(1, datasetRow.length() - 2);

			getline(s, datasetRow, '\t');
			//cout << datasetRow << " ";
			tempDate = datasetRow.substr(1, datasetRow.length() - 2);
			tempMonth = datasetRow.substr(5, 3);

			getline(s, datasetRow, '\t');
			//cout << datasetRow << " ";
			tempTw.tweetContent = datasetRow.substr(1, datasetRow.length() - 2);

			getline(s, datasetRow, '\n');
			//cout << datasetRow << endl;
			tempTw.hashtags = datasetRow.substr(1, datasetRow.length() - 2);

			FindKeywordFrequency(&tempTw, tempMonth);

			datasetContents[make_pair(tempDate, tempMonth)].push_back(tempTw);
		}
		s.close();
	}
	
	map<pair<string, string>, vector<TweetData>>* returnContents() {
		return &datasetContents;
	}

	vector<int> returnKeywordFreq() {
		return KeywordFrequency;
	}
};