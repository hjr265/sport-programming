// In the name of Allah, Most Gracious, Most Merciful

// TopCoder/SRM 302 Div 2/250
// Noun Reform
// implementation
// http://community.topcoder.com/stat?c=problem_statement&pm=6375&rd=9823
// (NounReform) makePlural(vector<string>) vector<string>
// AC (235)

#include <string>
#include <vector>

using namespace std;

class NounReform {
public:
	bool hasEnding(string const &fullString, string const &ending) {
		return fullString.length() >= ending.length() && (0 == fullString.compare(fullString.length()-ending.length(), ending.length(), ending));
	}

	string makePlural(string noun) {
		if(hasEnding(noun, "s") || hasEnding(noun, "z") || hasEnding(noun, "x") || hasEnding(noun, "ch") || hasEnding(noun, "sh"))
			return noun+"es";
		if(hasEnding(noun, "ay") || hasEnding(noun, "ey") || hasEnding(noun, "iy") || hasEnding(noun, "oy") || hasEnding(noun, "uy"))
			return noun+"s";
		if(hasEnding(noun, "y"))
			return noun.substr(0, noun.size()-1)+"ies";
		return noun+"s";
	}
	
	vector<string> makePlural(vector<string> nouns) {
		vector<string> result;
		for(int i = 0; i < nouns.size(); ++i)
			result.push_back(makePlural(nouns[i]));
		return result;
	}
};
