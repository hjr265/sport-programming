// In the name of Allah, Most Gracious, Most Merciful

// TopCoder/SRM 547 Div 2/500
// Pillars Div Two
// dp, geometry
// http://community.topcoder.com/stat?c=problem_statement&pm=12075&rd=14739
// (PillarsDivTwo) maximalLength(vector<int>, int) double
// AC (398)

#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

class PillarsDivTwo {
	vector<int> height;
	int w;
	
	struct State {
		double v;
		bool t;
		
		State() {}
		
		State(double v_) : v(v_) {
			
		}
	};
	
	State D[52][102];
	
	State dp(int i, int j) {
		if(i >= height.size())
			return State(0);
		State &r = D[i][j];
		if(!r.t) {
			r.v = 0;
			for(int h = 1; h <= height[i]; ++h)
				r.v = max(r.v, dp(i+1, h).v+(sqrt(w*w+(j-h)*(j-h))));
			r.t = true;
		}
		return r;
	}
	
public:
	double maximalLength(vector<int> height_, int w_) {
		height = height_;
		w = w_;
		double r = 0;
		CLR(D);
		for(int h = 1; h <= height[0]; ++h)
			r = max(r, dp(1, h).v);
		return r;
	}
};
