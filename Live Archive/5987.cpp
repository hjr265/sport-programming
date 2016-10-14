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

int S[10007];
vector<int> R;

int main() {
	SET(S, 0);
	for(vlong i = 2; i < 10007; ++i) if(!S[i]) {
		for(vlong j = i; j < 10007; j += i)
			++S[j];
	}
	
	for(int i = 2; i < 10007; ++i) if(S[i] >= 3)
		R.push_back(i);
	
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		cout << R[n-1] << endl;
	}
	return 0;
}
