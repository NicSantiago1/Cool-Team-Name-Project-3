#include "DandA3 Map.hpp"

class Node {
public: 
	string keyword;
	vector<TweetData*> tweets;
	Node(string given){	keyword = given; }
};

class datasetMaxHeap {
	map<pair<string, string>, vector<TweetData>> datasetContents;
	vector<pair<int, Node>> JanLeftHeap;
	vector<pair<int, Node>> JanRightHeap;

	vector<pair<int, Node>> FebLeftHeap;
	vector<pair<int, Node>> FebRightHeap;

	vector<pair<int, Node>> MarLeftHeap;
	vector<pair<int, Node>> MarRightHeap;

	vector<pair<int, Node>> AprLeftHeap;
	vector<pair<int, Node>> AprRightHeap;

	vector<pair<int, Node>> MayLeftHeap;
	vector<pair<int, Node>> MayRightHeap;

	vector<pair<int, Node>> JunLeftHeap;
	vector<pair<int, Node>> JunRightHeap;

	vector<pair<int, Node>> JulLeftHeap;
	vector<pair<int, Node>> JulRightHeap;

	vector<pair<int, Node>> AugLeftHeap;
	vector<pair<int, Node>> AugRightHeap;

	vector<pair<int, Node>> SepLeftHeap;
	vector<pair<int, Node>> SepRightHeap;

	vector<pair<int, Node>> OctLeftHeap;
	vector<pair<int, Node>> OctRightHeap;

	vector<pair<int, Node>> NovLeftHeap;
	vector<pair<int, Node>> NovRightHeap;

	vector<pair<int, Node>> DecLeftHeap;
	vector<pair<int, Node>> DecRightHeap;
public:
	vector<string> lefts = { "democrat", "liberals", "leftist", "biden", "dnc", "vice", "kamala", "blm", "black lives matter", "bernie", "aoc", "impeach", "socialist", "socialism", "communist",
	"communism", "medicare", "m4a", "yang", "buttigieg", "warren", "bloomberg" };
	vector<string> rights = { "republican", "conservative", "donald", "trump", "realdonaldtrump", "pence", "bannon", "roger stone", "manafort", "mcconnell", "fascist", "fascism" };

	// Gives the leftHeap and rightHeap vectors the strings and initializes the counts to 0
	void fillNodes() {
		for (int i = 0; i < lefts.size(); i++) {
			JanLeftHeap.push_back(make_pair(0, Node(lefts.at(i))));
			JanRightHeap.push_back(make_pair(0, Node(rights.at(i))));

			FebLeftHeap.push_back(make_pair(0, Node(lefts.at(i))));
			FebRightHeap.push_back(make_pair(0, Node(rights.at(i))));

			MarLeftHeap.push_back(make_pair(0, Node(lefts.at(i))));
			MarRightHeap.push_back(make_pair(0, Node(rights.at(i))));

			AprLeftHeap.push_back(make_pair(0, Node(lefts.at(i))));
			AprRightHeap.push_back(make_pair(0, Node(rights.at(i))));

			MayLeftHeap.push_back(make_pair(0, Node(lefts.at(i))));
			MayRightHeap.push_back(make_pair(0, Node(rights.at(i))));

			JunLeftHeap.push_back(make_pair(0, Node(lefts.at(i))));
			JunRightHeap.push_back(make_pair(0, Node(rights.at(i))));

			JulLeftHeap.push_back(make_pair(0, Node(lefts.at(i))));
			JulRightHeap.push_back(make_pair(0, Node(rights.at(i))));

			AugLeftHeap.push_back(make_pair(0, Node(lefts.at(i))));
			AugRightHeap.push_back(make_pair(0, Node(rights.at(i))));

			SepLeftHeap.push_back(make_pair(0, Node(lefts.at(i))));
			SepRightHeap.push_back(make_pair(0, Node(rights.at(i))));

			OctLeftHeap.push_back(make_pair(0, Node(lefts.at(i))));
			OctRightHeap.push_back(make_pair(0, Node(rights.at(i))));

			NovLeftHeap.push_back(make_pair(0, Node(lefts.at(i))));
			NovRightHeap.push_back(make_pair(0, Node(rights.at(i))));

			DecLeftHeap.push_back(make_pair(0, Node(lefts.at(i))));
			DecRightHeap.push_back(make_pair(0, Node(rights.at(i))));
		}
	}

	string strLower(string in) {
		string out = "";
		for (int i = 0; i < in.length(); i++) {
			out += tolower(in.at(i));
		}
		return out;
	}

	// Fills the leftHeap and rightHeap vectors' the tweets vector and increases the counts when found
	void fillNodes2() {
		map<pair<string, string>, vector<TweetData>>::iterator iter;
		for (iter = datasetContents.begin(); iter != datasetContents.end(); iter++) {
			if (iter->first.second == "Jan") {															// Chooses tweet if the tweet's month is the target month
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;								// Iterate through the tweet's and puts the content in string
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(JanLeftHeap[j].second.keyword)) != string::npos) {			// Checks tweet for a leftist keyword and adds to the heap array
							JanLeftHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							JanLeftHeap[j].first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(JanRightHeap[j].second.keyword)) != string::npos) {			// Checks tweet for a rightist keyword and adds to the heap array
							JanRightHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							JanRightHeap[j].first++;
						}
					}
				}
			}
			else if (iter->first.second == "Feb") {														
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;					
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(FebLeftHeap[j].second.keyword)) != string::npos) {
							FebLeftHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							FebLeftHeap[j].first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(FebRightHeap[j].second.keyword)) != string::npos) {
							FebRightHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							FebRightHeap[j].first++;
						}
					}
				}
			}
			else if (iter->first.second == "Mar") {
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(MarLeftHeap[j].second.keyword)) != string::npos) {
							MarLeftHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							MarLeftHeap[j].first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(MarRightHeap[j].second.keyword)) != string::npos) {
							MarRightHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							MarRightHeap[j].first++;
						}
					}
				}
			}
			else if (iter->first.second == "Apr") {
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(AprLeftHeap[j].second.keyword)) != string::npos) {
							AprLeftHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							AprLeftHeap[j].first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(AprRightHeap[j].second.keyword)) != string::npos) {
							AprRightHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							AprRightHeap[j].first++;
						}
					}
				}
			}
			else if (iter->first.second == "May") {
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(MayLeftHeap[j].second.keyword)) != string::npos) {
							MayLeftHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							MayLeftHeap[j].first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(MayRightHeap[j].second.keyword)) != string::npos) {
							MayRightHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							MayRightHeap[j].first++;
						}
					}
				}
			}
			else if (iter->first.second == "Jun") {
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(JunLeftHeap[j].second.keyword)) != string::npos) {
							JunLeftHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							JunLeftHeap[j].first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(JunRightHeap[j].second.keyword)) != string::npos) {
							JunRightHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							JunRightHeap[j].first++;
						}
					}
				}
			}
			else if (iter->first.second == "Jul") {														
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;					
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(JulLeftHeap[j].second.keyword)) != string::npos) {
							JulLeftHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							JulLeftHeap[j].first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(JulRightHeap[j].second.keyword)) != string::npos) {
							JulRightHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							JulRightHeap[j].first++;
						}
					}
				}
			}
			else if (iter->first.second == "Aug") {
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(AugLeftHeap[j].second.keyword)) != string::npos) {
							AugLeftHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							AugLeftHeap[j].first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(AugRightHeap[j].second.keyword)) != string::npos) {
							AugRightHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							AugRightHeap[j].first++;
						}
					}
				}
			}
			else if (iter->first.second == "Sep") {														
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;					
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(SepLeftHeap[j].second.keyword)) != string::npos) {
							SepLeftHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							SepLeftHeap[j].first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(SepRightHeap[j].second.keyword)) != string::npos) {
							SepRightHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							SepRightHeap[j].first++;
						}
					}
				}
			}
			else if (iter->first.second == "Oct") {
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(OctLeftHeap[j].second.keyword)) != string::npos) {
							OctLeftHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							OctLeftHeap[j].first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(OctRightHeap[j].second.keyword)) != string::npos) {
							OctRightHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							OctRightHeap[j].first++;
						}
					}
				}
			}
			else if (iter->first.second == "Nov") {
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(NovLeftHeap[j].second.keyword)) != string::npos) {
							NovLeftHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							NovLeftHeap[j].first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(NovRightHeap[j].second.keyword)) != string::npos) {
							NovRightHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							NovRightHeap[j].first++;
						}
					}
				}
			}
			else if (iter->first.second == "Dec") {
				for (int i = 0; i < iter->second.size(); i++) {
					string TweetContent = iter->second.at(i).tweetContent;
					for (int j = 0; j < lefts.size(); j++) {
						if (TweetContent.find(strLower(DecLeftHeap[j].second.keyword)) != string::npos) {
							DecLeftHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							DecLeftHeap[j].first++;
						}
					}
					for (int j = 0; j < rights.size(); j++) {
						if (TweetContent.find(strLower(DecRightHeap[j].second.keyword)) != string::npos) {
							DecRightHeap[j].second.tweets.push_back(&(iter->second.at(i)));
							DecRightHeap[j].first++;
						}
					}
				}
			}
		}
	}

	void makeHeap() {

	}

	// constructor for the Max Heap. Given the month string so that it can be used to find which month's tweets to take data from
	datasetMaxHeap(map<pair<string, string>, vector<TweetData>> _datasetContents) { datasetContents = _datasetContents; }
};

