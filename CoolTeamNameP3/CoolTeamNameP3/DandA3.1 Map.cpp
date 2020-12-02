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
public:
	void AddDatasetValues();
private:
	// A vector in case two tweets were published at the same time
	map<string, vector<TweetData>> datasetContents;
};

int main() {
	datasetMap dataset;
	dataset.AddDatasetValues();
}

void datasetMap::AddDatasetValues() {
	string tempDate;

	fstream s;
	s.open("full_dataset_reduced.csv", ios::in);

	string datasetRow;
	string partOfRow;

	string ID, date, tweetContent, hashtags;

	while (getline(s, datasetRow, '\n')) {
		stringstream s2;
		s2.str(datasetRow);

		TweetData tempTweet;

		//
		//Tweet ID, Date, and Content delete the quotation marks before and after each of the extracted string
		//	Date is used as the key for the map
		//
		//Tweet Hashtag List deletes the brackets before and after the extracted string of hashtags
		//	The string formerly in the brackets can be separated using "," as a delimiter
		//

		// Tweet ID
		getline(s2, partOfRow, '\t');
		partOfRow.erase(partOfRow.end());
		partOfRow.erase(partOfRow.begin());
		tempTweet.ID = partOfRow;

		// Tweet Date
		getline(s2, partOfRow, '\t');
		partOfRow.erase(partOfRow.end());
		partOfRow.erase(partOfRow.begin());
		tempDate = partOfRow;

		// Tweet Content
		getline(s2, partOfRow, '\t');
		partOfRow.erase(partOfRow.end());
		partOfRow.erase(partOfRow.begin());
		tempTweet.tweetContent = partOfRow;

		// Tweet Hashtag List
		getline(s2, partOfRow, '\t');
		partOfRow.erase(partOfRow.end());
		partOfRow.erase(partOfRow.begin());
		tempTweet.tweetContent = partOfRow;

		datasetContents[tempDate].push_back(tempTweet);
	}
}