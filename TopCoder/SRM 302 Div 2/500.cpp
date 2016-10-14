// In the name of Allah, Most Gracious, Most Merciful

// TopCoder/SRM 302 Div 2/500
// X Ball Game
// implementation
// http://community.topcoder.com/stat?c=problem_statement&pm=6387&rd=9823
// (XBallGame) newStatistics(vector<string>) vector<string>
// AC (430)

#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class XBallGame {
	map<string, set<string> > nameposmap;
	
public:
	vector<string> newStatistics(vector<string> placeboard) {
		for(int i = 0; i < placeboard.size(); ++i) {
			string name = placeboard[i].substr(0, placeboard[i].size()-3),
				position = placeboard[i].substr(placeboard[i].size()-2);
			nameposmap[name].insert(position);
		}
		vector<string> result;
		for(int i = 0; i < placeboard.size(); ++i) {
			string name = placeboard[i].substr(0, placeboard[i].size()-3),
				position = placeboard[i].substr(placeboard[i].size()-2);
			string row = placeboard[i];
			set<string> allpositions = nameposmap[name];
			allpositions.erase(position);
			for(set<string>::iterator it = allpositions.begin(); it != allpositions.end(); ++it) {
				row += ",";
				row += *it;
			}
			result.push_back(row);
		}
		return result;
	}
};
