#include "DandA3 Map.cpp"
#include <queue>

class Node {
public: 
	string keyword;
	vector<TweetData*> tweets;
	Node(string given){	keyword = given; }
};

class datasetMaxHeap {
	map<pair<string, string>, vector<TweetData>> datasetContents;

	// Contains all the vectors of keywords and their counts. 12 total in each one for 12 months.
	// Vector for month. Pair contains int for number of appearances and Node for each keyword
	vector <vector<pair<int, Node>>> LeftHeaps;
	vector <vector<pair<int, Node>>> RightHeaps;

	vector<priority_queue<pair<int, Node>>> LeftMaxes;
	vector<priority_queue<pair<int, Node>>> RightMaxes;

public:
	// Keyword vectors
	vector<string> lefts = { "democrat", "liberals", "leftist", "biden", "dnc", "vice", "kamala", "blm", "black lives matter", "bernie", "aoc", "impeach", "socialist", "socialism", "communist",
	"communism", "medicare", "m4a", "yang", "buttigieg", "warren", "bloomberg" };
	vector<string> rights = { "republican", "conservative", "donald", "trump", "realdonaldtrump", "pence", "bannon", "roger stone", "manafort", "mcconnell", "fascist", "fascism", "shapiro" };

	//Creates a left word and right word vector for each month. 24 vectors in total. Adds each keyword in the vectors and initializes the word counts to 0
	void fillNodes() {
		for (int i = 0; i < 12; i++) {
			vector<pair<int, Node>> leftTemp;
			vector<pair<int, Node>> rightTemp;
			for (int j = 0; j < lefts.size(); j++) {
				leftTemp.push_back(make_pair(0, Node(lefts.at(j))));
			}	
			for (int j = 0; j < rights.size(); j++) {
				rightTemp.push_back(make_pair(0, Node(rights.at(j))));
			}

			LeftHeaps.push_back(leftTemp);
			RightHeaps.push_back(rightTemp);
		}
	}

	string strLower(string in) {
		string out = "";
		for (int i = 0; i < in.length(); i++) {
			out += tolower(in.at(i));
		}
		return out;
	}

	//Function to convert the month string identifiers to numbers 1-12
	string monthStrs[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	int monthIndex(string mnth) {
		for (int i = 0; i < 12; i++) {
			if (!mnth.compare(monthStrs[i]))
				return i;
		}
		return -1;
	}

	// Fills the leftHeap and rightHeap vectors' the tweets vector and increases the counts when found
	void fillNodes2() {
		map<pair<string, string>, vector<TweetData>>::iterator iter;
		for (iter = datasetContents.begin(); iter != datasetContents.end(); iter++) {
			int mon = monthIndex(iter->first.second);
			switch (mon) {
			case 1:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[0].at(j).second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[0].at(j).second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[0].at(j).first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[0].at(j).second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[0].at(j).second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[0].at(j).first++;
						}
					}
				}
			case 2:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[1].at(j).second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[1].at(j).second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[1].at(j).first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[1].at(j).second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[1].at(j).second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[1].at(j).first++;
						}
					}
				}
			case 3:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[2].at(j).second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[2].at(j).second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[2].at(j).first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[2].at(j).second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[2].at(j).second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[2].at(j).first++;
						}
					}
				}
			case 4:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[3].at(j).second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[3].at(j).second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[3].at(j).first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[3].at(j).second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[3].at(j).second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[3].at(j).first++;
						}
					}
				}
			case 5:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[4].at(j).second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[4].at(j).second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[4].at(j).first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[4].at(j).second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[4].at(j).second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[4].at(j).first++;
						}
					}
				}
			case 6:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[5].at(j).second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[5].at(j).second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[5].at(j).first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[5].at(j).second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[5].at(j).second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[5].at(j).first++;
						}
					}
				}
			case 7:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[6].at(j).second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[6].at(j).second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[6].at(j).first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[6].at(j).second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[6].at(j).second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[6].at(j).first++;
						}
					}
				}
			case 8:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[7].at(j).second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[7].at(j).second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[7].at(j).first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[7].at(j).second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[7].at(j).second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[7].at(j).first++;
						}
					}
				}
			case 9:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[8].at(j).second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[8].at(j).second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[8].at(j).first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[8].at(j).second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[8].at(j).second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[8].at(j).first++;
						}
					}
				}
			case 10:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[9].at(j).second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[9].at(j).second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[9].at(j).first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[9].at(j).second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[9].at(j).second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[9].at(j).first++;
						}
					}
				}
			case 11:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[10].at(j).second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[10].at(j).second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[10].at(j).first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[10].at(j).second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[10].at(j).second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[10].at(j).first++;
						}
					}
				}
			case 12:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[11].at(j).second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[11].at(j).second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[11].at(j).first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[11].at(j).second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[11].at(j).second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[11].at(j).first++;
						}
					}
				}
			}

		}
	}

	void makeHeap() {
		for (int i = 0; i < LeftHeaps.size(); i++) {
			priority_queue<pair<int, Node>> tempLeft;
			for (int j = 0; j < LeftHeaps[i].size(); j++) {
				tempLeft.push(make_pair(LeftHeaps[i].at(j).first, LeftHeaps[i].at(j).second));
			}
			LeftMaxes.push_back(tempLeft);
		}

		for (int i = 0; i < RightHeaps.size(); i++) {
			priority_queue<pair<int, Node>> tempRight;
			for (int j = 0; j < LeftHeaps[i].size(); j++) {
				tempRight.push(make_pair(LeftHeaps[i].at(j).first, LeftHeaps[i].at(j).second));
			}
			RightMaxes.push_back(tempRight);
		}
	}

	// constructor for the Max Heap
	datasetMaxHeap(map<pair<string, string>, vector<TweetData>> _datasetContents) { datasetContents = _datasetContents; }
};

