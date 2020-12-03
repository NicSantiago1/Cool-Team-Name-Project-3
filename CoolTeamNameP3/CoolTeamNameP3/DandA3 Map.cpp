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
	void FindKeywordFrequency();
};

class datasetMap {
public:
	void AddDatasetValues();
	void AddExistingValues(string date, TweetData temp);
	map<string, vector<TweetData>> returnContents();
private:
	// A vector in case two tweets were published at the same time
	map<string, vector<TweetData>> datasetContents;
};

// Dataset function(s)
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

		/*
		Tweet ID, Date, and Content delete the quotation marks before and after each of the extracted string
			Date is used as the key for the map

		Tweet Hashtag List deletes the brackets before and after the extracted string of hashtags
			The string formerly in the brackets can be separated using "," as a delimiter
		*/

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
		tempTweet.FindKeywordFrequency();

		// Tweet Hashtag List
		getline(s2, partOfRow, '\t');
		partOfRow.erase(partOfRow.end());
		partOfRow.erase(partOfRow.begin());
		tempTweet.tweetContent = partOfRow;

		datasetContents[tempDate].push_back(tempTweet);
	}
}

map<string, vector<TweetData>> datasetMap::returnContents() {
	return datasetContents;
}

void datasetMap::AddExistingValues(string date, TweetData temp) {
	datasetContents[date].push_back(temp);
}

// TweetData function(s)
void TweetData::FindKeywordFrequency() {
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


// Main function
int main() {
	// Create a map for the entire year/dataset
	datasetMap yearDataset;
	yearDataset.AddDatasetValues();

	// Create maps for every month
	datasetMap janDataset;
	datasetMap febDataset;
	datasetMap marDataset;
	datasetMap aprDataset;
	datasetMap mayDataset;
	datasetMap junDataset;
	datasetMap julDataset;
	datasetMap augDataset;
	datasetMap sepDataset;
	datasetMap octDataset;
	datasetMap novDataset;
	datasetMap decDataset;
	// Iterate through yearDataset and distribute values (I don't think this should be a dataset function unless you want the parameters to be 12 different maps passed by reference)
	for (auto iter : yearDataset.returnContents()) {
		if (iter.first.find("Jan") != string::npos) {
			for (int i = 0; i < iter.second.size(); i++) {
				janDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.find("Feb") != string::npos) {
			for (int i = 0; i < iter.second.size(); i++) {
				febDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.find("Mar") != string::npos) {
			for (int i = 0; i < iter.second.size(); i++) {
				marDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.find("Apr") != string::npos) {
			for (int i = 0; i < iter.second.size(); i++) {
				aprDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.find("May") != string::npos) {
			for (int i = 0; i < iter.second.size(); i++) {
				mayDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.find("Jun") != string::npos) {
			for (int i = 0; i < iter.second.size(); i++) {
				junDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.find("Jul") != string::npos) {
			for (int i = 0; i < iter.second.size(); i++) {
				julDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.find("Aug") != string::npos) {
			for (int i = 0; i < iter.second.size(); i++) {
				augDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.find("Sep") != string::npos) {
			for (int i = 0; i < iter.second.size(); i++) {
				sepDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.find("Oct") != string::npos) {
			for (int i = 0; i < iter.second.size(); i++) {
				octDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.find("Nov") != string::npos) {
			for (int i = 0; i < iter.second.size(); i++) {
				novDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.find("Dec") != string::npos) {
			for (int i = 0; i < iter.second.size(); i++) {
				decDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
	}
}



