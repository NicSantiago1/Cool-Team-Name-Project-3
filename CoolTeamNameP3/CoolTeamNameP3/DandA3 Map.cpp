Skip to content
Search or jump to…

Pulls
Issues
Marketplace
Explore

@InvalidReality
Learn Git and GitHub without any code!
Using the Hello World guide, you’ll start a branch, write comments, and open a pull request.


NicSantiago1
/
Cool - Team - Name - Project - 3
2
00
Code
Issues
Pull requests
Actions
Projects
Wiki
Security
Insights
Cool - Team - Name - Project - 3 / CoolTeamNameP3 / CoolTeamNameP3 / DandA3 Map.cpp
@jacksonavery
jacksonavery taking input now works, month sets WIP
Latest commit 6ef7fe8 2 hours ago
History
2 contributors
@InvalidReality@jacksonavery
224 lines(199 sloc)  6.32 KB

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
	map<pair<string, string>, vector<TweetData>> returnContents();
private:
	// A vector in case two tweets were published at the same time
	map<pair<string, string>, vector<TweetData>> datasetContents;
};

// Dataset function(s)
void datasetMap::AddDatasetValues() {
	string tempDate, tempMonth;

	fstream s;
	s.open("full_dataset_reduced3.tsv", ios::in);

	string datasetRow;
	string partOfRow;

	string ID, date, tweetContent, hashtags;

	int i = 0;
	//while (getline(s, datasetRow, '\n') && i < 10) {
	//	i++;
	//	stringstream s2;
	//	s2.str(datasetRow);
	//
	//	TweetData tempTweet;
	//
	//	/*
	//	Tweet ID, Date, and Content delete the quotation marks before and after each of the extracted string
	//		Date is used as the key for the map
	//
	//	Tweet Hashtag List deletes the brackets before and after the extracted string of hashtags
	//		The string formerly in the brackets can be separated using "," as a delimiter
	//	*/
	//
	//	// Tweet ID
	//	getline(s2, partOfRow, '\t');
	//	tempTweet.ID = partOfRow.substr(1, partOfRow.length() - 2);
	//
	//	// Tweet Date
	//	getline(s2, partOfRow, '\t');
	//	tempDate = partOfRow.substr(1, partOfRow.length() - 2);
	//
	//	// Tweet Content
	//	getline(s2, partOfRow, '\t');
	//	tempTweet.tweetContent = partOfRow.substr(1, partOfRow.length() - 2);
	//	tempTweet.FindKeywordFrequency();
	//
	//	// Tweet Hashtag List
	//	getline(s2, partOfRow, '\t');
	//	tempTweet.tweetContent = partOfRow.substr(1, partOfRow.length() - 2);
	//
	//	datasetContents[tempDate].push_back(tempTweet);
	//}
	while (getline(s, datasetRow, '\t') && i < 10) {
		i++;
		TweetData tempTw;
		tempTw.ID = datasetRow.substr(1, datasetRow.length() - 2);

		getline(s, datasetRow, '\t');
		tempDate = datasetRow.substr(1, datasetRow.length() - 2);
		// CHECK - from indexes 5 to 7?
		tempMonth = datasetRow.substr(5, 7);

		getline(s, datasetRow, '\t');
		tempTw.tweetContent = datasetRow.substr(1, datasetRow.length() - 2);
		tempTw.FindKeywordFrequency();

		getline(s, datasetRow, '\n');
		tempTw.hashtags = datasetRow.substr(1, datasetRow.length() - 2);

		datasetContents[make_pair(tempDate, tempMonth)].push_back(tempTw);
	}

	//temp print func
	//for (auto it : datasetContents) {
	//	std::cout << it.first << " " << it.second.at(0).ID << " " << it.second.at(0).tweetContent << " " << it.second.at(0).hashtags << "\n";
	//}
}

map<pair<string, string>, vector<TweetData>> datasetMap::returnContents() {
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



	/* for now
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
		if (iter.first.compare(4, 3, "Jan")) {
			for (int i = 0; i < iter.second.size(); i++) {
				janDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.compare(4, 3, "Feb")) {
			for (int i = 0; i < iter.second.size(); i++) {
				febDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.compare(4, 3, "Mar")) {
			for (int i = 0; i < iter.second.size(); i++) {
				marDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.compare(4, 3, "Apr")) {
			for (int i = 0; i < iter.second.size(); i++) {
				aprDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.compare(4, 3, "May")) {
			for (int i = 0; i < iter.second.size(); i++) {
				mayDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.compare(4, 3, "Jun")) {
			for (int i = 0; i < iter.second.size(); i++) {
				junDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.compare(4, 3, "Jul")) {
			for (int i = 0; i < iter.second.size(); i++) {
				julDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.compare(4, 3, "Aug")) {
			for (int i = 0; i < iter.second.size(); i++) {
				augDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.compare(4, 3, "Sep")) {
			for (int i = 0; i < iter.second.size(); i++) {
				sepDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.compare(4, 3, "Oct")) {
			for (int i = 0; i < iter.second.size(); i++) {
				octDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.compare(4, 3, "Nov")) {
			for (int i = 0; i < iter.second.size(); i++) {
				novDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
		else if (iter.first.compare(4, 3, "Dec")) {
			for (int i = 0; i < iter.second.size(); i++) {
				decDataset.AddExistingValues(iter.first, iter.second[i]);
			}
		}
	}
	*/
}



