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
		vector<vlong> L, C;
		vlong S = 0;
		C.push_back(0);
		for(int i = 0; i < N; ++i) {
			vlong x;
			cin >> x;
			L.push_back(x);
			S += x;
			C.push_back(C[i]+x);
		}
		vlong Z = 1LL<<50;
		for(int i = 0; i < N; ++i) {
			Z = min(Z, S-L[i]+C[i]);
			Z = min(Z, S-L[i]+(S-C[i+1]));
		}
		cout << Z << endl;
	}
	return 0;
}
