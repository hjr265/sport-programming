// In the name of Allah, Most Gracious, Most Merciful

// TopCoder/SRM 547 Div 2/1000
// Relatively Prime Subset
// implementation
// http://community.topcoder.com/stat?c=problem_statement&pm=12074&rd=14739
// (RelativelyPrimeSubset) findSize(vector<int>) int
// AC (513)

#include <cstring>
#include <algorithm>
#include <vector>

#define CLR(c) memset(c, 0, sizeof(c))
#define ALL(c) c.begin(), c.end()

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int X[102];

bool cmpX(int a, int b) {
	return X[a] > X[b];
}

class RelativelyPrimeSubset {
public:
	int findSize(vector<int> S) {
		vector<int> r;
		int n = S.size();
		for(int l = 0; l < n; ++l) {
			CLR(X);
			for(int i = 0; i < S.size(); ++i) {
				for(int j = 0; j < S.size(); ++j) if(i != j && gcd(S[i], S[j]) > 1)
					X[S[i]]++;
			}
			sort(ALL(S), cmpX);
			int u = S[S.size()-1];
			bool k = true;
			for(int i = 0; i < r.size(); ++i) if(gcd(u, r[i]) > 1) {
				k = false;
				break;
			}
			if(k)
				r.push_back(u);
			S.pop_back();
		}
		return r.size();
	}
};
