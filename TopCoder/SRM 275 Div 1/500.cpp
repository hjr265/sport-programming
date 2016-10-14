// In the name of Allah, Most Gracious, Most Merciful

// TopCoder/SRM 275 Div 1/500
// Horoscope
// dp
// http://community.topcoder.com/stat?c=problem_statement&pm=5909&rd=8072
// (Horoscope) maxGoodDays(vector<string>, int, int) int
// AC (454)

#include <cmath>
#include <cstring>
#include <string>
#include <vector>

#define SET(c, v) memset(c, v, sizeof(c))

using namespace std;

class Horoscope {
	string predictions;
	int R, W;
	int D[2502][52][52];
	
	int dp(int i, int j, int k) {
		if(i == predictions.size())
			return 0;
		int &r = D[i][j][k];
		if(r == -1) {
			r = 0;
			
			if(predictions[i] == 'G') {
				if(j < R)
					r = max(r, dp(i+1, j+1, 0)+1);
				if(k < W)
					r = max(r, dp(i+1, 0, k+1));
			} else {
				if(j < R)
					r = max(r, dp(i+1, j+1, 0));
				if(k < W)
					r = max(r, dp(i+1, 0, k+1)+1);
			}
			
		}
		return r;
	}
	
public:
	int maxGoodDays(vector<string> predictions_, int R_, int W_) {
		predictions = "";
		for(int i = 0; i < predictions_.size(); ++i)
			predictions += predictions_[i];

		R = R_;
		W = W_;
		SET(D, -1);
		return dp(0, 0, 0);
	}
};
