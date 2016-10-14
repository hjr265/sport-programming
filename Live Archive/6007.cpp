// In the name of Allah, Most Gracious, Most Merciful

// /
// 
// 
// 
// 
// ??

#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define SET(c, v) memset(c, v, sizeof(c))
#define LEN(c) (sizeof(c)/sizeof(c[0]))
#define ALL(c) c.begin(), c.end()
#define SLC(c, n) c, c+(n)

using namespace std;

typedef unsigned int uint;
typedef long long vlong;
typedef unsigned long long uvlong;

const double EPS = 1e-12;
const double PI = acos(-1.0);

enum {
	
};

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<string> A[2];
		string W;
		int i = 0;
		while(N--) {
			string X;
			cin >> X;
			if(X[0] != '#') {
				W = X;
				++i;
			} else {
				A[i].push_back(X);
			}
		}
		string R;
		for(int j = 1; j >= 0; --j) {
			for(int i = 0; i < A[j].size(); ++i)
				R += " ", R += A[j][i];
			if(j == 1 && W.size() > 0)
				R += " ", R += W;
		}
		cout << R.substr(1) << endl;
	}
	return 0;
}
