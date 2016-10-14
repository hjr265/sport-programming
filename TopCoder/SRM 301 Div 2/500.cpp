// In the name of Allah, Most Gracious, Most Merciful

// TopCoder/SRM 301 Div 2/500
// Indicator Motion Reverse
// implementation
// http://community.topcoder.com/stat?c=problem_statement&pm=6172&rd=9822
// (IndicatorMotionReverse) getMinProgram(vector<string>) string
// AC (192)

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class IndicatorMotionReverse {
public:
	string getMinProgram(vector<string> actions) {
		string A = "";
		for(int i = 0; i < actions.size(); ++i)
			A += actions[i];
		string B = "";
		for(int i = 1; i < A.size(); ++i) switch(A[i-1]) {
		case '|':
			switch(A[i]) {
			case '|':
				B += "S";
				break;
			case '/':
				B += "R";
				break;
			case '-':
				B += "F";
				break;
			case 'N':
				B += "L";
				break;
			}
			break;
		case '/':
			switch(A[i]) {
			case '|':
				B += "L";
				break;
			case '/':
				B += "S";
				break;
			case '-':
				B += "R";
				break;
			case 'N':
				B += "F";
				break;
			}
			break;
		case '-':
			switch(A[i]) {
			case '|':
				B += "F";
				break;
			case '/':
				B += "L";
				break;
			case '-':
				B += "S";
				break;
			case 'N':
				B += "R";
				break;
			}
			break;
		case 'N':
			switch(A[i]) {
			case '|':
				B += "R";
				break;
			case '/':
				B += "F";
				break;
			case '-':
				B += "L";
				break;
			case 'N':
				B += "S";
				break;
			}
			break;
		}
		vector<string> C;
		string R = "";
		for(int i = 0; i < B.size(); ) {
			char X = B[i];
			int j = i;
			while(j < B.size() && B[j] == X && j-i < 99)
				++j;
			int s = j-i;
			string Y = "";
			Y += X;
			Y += s/10+'0';
			Y += s%10+'0';
			i = j;
			C.push_back(Y);
			if(Y.size() > 35)
				break;
		}
		for(int i = 0; i < C.size(); ) {
			char X = C[i][0];
			int j = i;
			while(j < C.size() && C[j][0] == X)
				++j;
			sort(C.begin()+i, C.begin()+j);
			i = j;
		}
		for(int i = 0; i < C.size(); ++i)
			R += C[i];
		if(R.size() > 100)
			R = R.substr(0, 97)+"...";
		return R;
	}
};
