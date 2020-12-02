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
private:

};

class datasetMap {
public:
	map<string, TweetData> datasetContents;
private:
	// Some functions?
};

int main() {
	datasetMap dataset;
	string tempDate;

	fstream s;
	s.open("full_dataset_reduced.csv", ios::in);
	int position;
	string line;
	string ID, date, tweetContent, hashtags;
	getline(s, line);
	while (!line.empty) {
		TweetData tempTweet;
		// Deleting the first quotation mark
		line.erase(line.begin());

		// Tweet ID
		position = line.find('","');
		tempTweet.ID = line.substr(0, position - 1);
		line.erase(0, position + 2);

		// Tweet Date
		position = line.find('","');
		tempDate = line.substr(0, position - 1);
		line.erase(0, position + 2);

		// Tweet Content
		position = line.find('",[');
		tempTweet.tweetContent = line.substr(0, position - 1);
		line.erase(0, position + 2);

		// Tweet Hashtag List
		position = line.find('],');
		tempTweet.hashtags = line.substr(0, position - 1);
		line.erase(0, position + 1);

		dataset.datasetContents[tempDate] = tempTweet;
	}
}

/*
		stringstream currentLine(line);
		while (getline(currentLine, temp, ',')) {

		}
		*/
