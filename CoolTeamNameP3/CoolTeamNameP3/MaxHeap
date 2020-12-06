#include "Source.cpp"
#include <unordered_map>

class Node {
public: 
	string keyword;
	vector<TweetData*> tweets;
	Node(string given){	keyword = given; }
};

class datasetMaxHeap {
	map<pair<string, string>, vector<TweetData>> datasetContents;
	vector<pair<int, Node>> leftHeap;
	vector<pair<int, Node>> rightHeap;
	string month;
public:
	vector<string> lefts = { "democrat", "liberals", "leftist", "biden", "dnc", "vice", "kamala", "blm", "black lives matter", "bernie", "aoc", "impeach", "socialist", "socialism", "communist",
	"communism", "medicare", "m4a", "yang", "buttigieg", "warren", "bloomberg" };
	vector<string> rights = { "republican", "conservative", "donald", "trump", "realdonaldtrump", "pence", "bannon", "roger stone", "manafort", "mcconnell", "fascist", "fascism" };

	// Gives the leftHeap and rightHeap vectors the strings and initializes the counts to 0
	void fillNodes() {
		for (int i = 0; i < lefts.size(); i++) {
			leftHeap.push_back(make_pair(0, Node(lefts.at(i))));
			rightHeap.push_back(make_pair(0, Node(rights.at(i))));
		}
	}

	// Fills the leftHeap and rightHeap vectors' the tweets vector and increases the counts when found
	void fillNodes2() {
		map<pair<string, string>, vector<TweetData>>::iterator iter;
		for (iter = datasetContents.begin(); iter != datasetContents.end(); iter++) {
			if (iter->first.second == month) {															// Chooses tweet if the tweet's month is the target month
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(leftHeap[j].second.keyword) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							leftHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							leftHeap[j].first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(rightHeap[j].second.keyword) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							rightHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							rightHeap[j].first++;
						}
					}
				}
			}
		}



	}

	void makeHeap() {

	}

	// constructor for the Max Heap. Given the month string so that it can be used to find which month's tweets to take data from
	datasetMaxHeap(map<pair<string, string>, vector<TweetData>> _datasetContents, string _month) { datasetContents = _datasetContents; month = _month; }
};

