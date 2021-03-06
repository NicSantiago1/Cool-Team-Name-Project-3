#include "DandA3 Map.hpp"
#include <queue>

class Node {
public: 
	string keyword;
	vector<TweetData*> tweets;
	Node(string given){	keyword = given; }
};

struct intNodePair {
	pair<int, Node> contPair = make_pair(1,Node(""));
	intNodePair(pair<int, Node> in) {
		contPair = in;
	}

	intNodePair(const intNodePair&) = default;

	bool operator<(const intNodePair& in) const {
		if (this->contPair.first < in.contPair.first)
			return true;
		return false;
	}

};

class datasetMaxHeap {
	map<pair<string, string>, vector<TweetData>>* datasetContents;

	// Contains all the vectors of keywords and their counts. 12 total in each one for 12 months.
	// Vector for month. Pair contains int for number of appearances and Node for each keyword
	vector <vector<intNodePair>> LeftHeaps;
	vector <vector<intNodePair>> RightHeaps;

	vector<priority_queue<intNodePair>> LeftMaxes;
	vector<priority_queue<intNodePair>> RightMaxes;

public:
	// Keyword vectors
	vector<string> lefts = { "democrat", "liberals", "leftist", "biden", "dnc", "vice", "kamala", "blm", "black lives matter", "bernie", "aoc", "impeach", "socialist", "socialism", "communist",
	"communism", "medicare", "m4a", "yang", "buttigieg", "warren", "bloomberg" };
	vector<string> rights = { "republican", "conservative", "donald", "trump", "realdonaldtrump", "pence", "bannon", "roger stone", "manafort", "mcconnell", "fascist", "fascism", "shapiro" };

	//Creates a left word and right word vector for each month. 24 vectors in total. Adds each keyword in the vectors and initializes the word counts to 0
	void fillNodes() {
		for (int i = 0; i < 12; i++) {
			vector<intNodePair> leftTemp;
			vector<intNodePair> rightTemp;
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
		for (iter = datasetContents->begin(); iter != datasetContents->end(); iter++) {
			int mon = monthIndex(iter->first.second);
			switch (mon) {
			case 1:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[0].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[0].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[0].at(j).contPair.first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[0].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[0].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[0].at(j).contPair.first++;
						}
					}
				}
				break;
			case 2:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[1].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[1].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[1].at(j).contPair.first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[1].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[1].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[1].at(j).contPair.first++;
						}
					}
				}
				break;
			case 3:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[2].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[2].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[2].at(j).contPair.first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[2].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[2].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[2].at(j).contPair.first++;
						}
					}
				}
				break;
			case 4:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[3].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[3].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[3].at(j).contPair.first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[3].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[3].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[3].at(j).contPair.first++;
						}
					}
				}
				break;
			case 5:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[4].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[4].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[4].at(j).contPair.first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[4].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[4].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[4].at(j).contPair.first++;
						}
					}
				}
				break;
			case 6:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[5].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[5].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[5].at(j).contPair.first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[5].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[5].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[5].at(j).contPair.first++;
						}
					}
				}
				break;
			case 7:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[6].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[6].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[6].at(j).contPair.first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[6].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[6].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[6].at(j).contPair.first++;
						}
					}
				}
				break;
			case 8:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[7].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[7].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[7].at(j).contPair.first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[7].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[7].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[7].at(j).contPair.first++;
						}
					}
				}
				break;
			case 9:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[8].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[8].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[8].at(j).contPair.first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[8].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[8].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[8].at(j).contPair.first++;
						}
					}
				}
				break;
			case 10:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[9].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[9].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[9].at(j).contPair.first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[9].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[9].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[9].at(j).contPair.first++;
						}
					}
				}
				break;
			case 11:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[10].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[10].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[10].at(j).contPair.first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[10].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[10].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[10].at(j).contPair.first++;
						}
					}
				}
				break;
			case 12:
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(LeftHeaps[11].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							LeftHeaps[11].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							LeftHeaps[11].at(j).contPair.first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(RightHeaps[11].at(j).contPair.second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							RightHeaps[11].at(j).contPair.second.tweets.push_back(&(iter->second.at(i)));
							RightHeaps[11].at(j).contPair.first++;
						}
					}
				}
				break;
			}

		}
	}

	void makeHeap() {
		for (int i = 0; i < LeftHeaps.size(); i++) {
			priority_queue<intNodePair> tempLeft;
			for (int j = 0; j < LeftHeaps[i].size(); j++) {
				tempLeft.push(intNodePair(make_pair(LeftHeaps[i].at(j).contPair.first, LeftHeaps[i].at(j).contPair.second)));
			}
			LeftMaxes.push_back(tempLeft);
		}

		for (int i = 0; i < RightHeaps.size(); i++) {
			priority_queue<intNodePair> tempRight;
			for (int j = 0; j < RightHeaps[i].size(); j++) {
				tempRight.push(intNodePair(make_pair(RightHeaps[i].at(j).contPair.first, RightHeaps[i].at(j).contPair.second)));
			}
			RightMaxes.push_back(tempRight);
		}

		//for (auto it : LeftMaxes) {
		//	while (!it.empty()) {
		//		cout << it.top().contPair.first << ": " << it.top().contPair.second.keyword << ", ";
		//		it.pop();
		//	}
		//	cout << endl;
		//}
		//
		//for (auto it : RightMaxes) {
		//	while (!it.empty()) {
		//		cout << it.top().contPair.first << ": " << it.top().contPair.second.keyword << ", ";
		//		it.pop();
		//	}
		//	cout << endl;
		//}
	}

	void returnLeftHeaps(vector<vector<intNodePair>>* in) {
		for (auto it : LeftMaxes) {
			vector<intNodePair> temp;
			while (!it.empty()) {
				temp.push_back(it.top());
				it.pop();
			}
			in->push_back(temp);
		}
	}
	void returnRightHeaps(vector<vector<intNodePair>>* in) {
		for (auto it : RightMaxes) {
			vector<intNodePair> temp;
			while (!it.empty()) {
				temp.push_back(it.top());
				it.pop();
			}
			in->push_back(temp);
		}
	}

	// constructor for the Max Heap
	datasetMaxHeap(map<pair<string, string>, vector<TweetData>>* _datasetContents) { 
		datasetContents = _datasetContents; 
		fillNodes();
		fillNodes2();
		makeHeap();
	}
};

