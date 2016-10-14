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

vector<pair<int, vlong> > X[50];

vlong D[50];

vlong dp(int i) {
	if(i > 48)
		return 0;
	
	vlong &r = D[i];
	if(r == -1) {
		r = 0;
		r = max(r, dp(i+1));
		for(int j = 0; j < X[i].size(); ++j)
			r = max(r, dp(X[i][j].first)+X[i][j].second);
	}
	return r;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		for(int i = 0; i < 50; ++i)
			X[i].clear();
			
		int N;
		scanf("%d", &N);
		for(int i = 0; i < N; ++i) {
			int S, E, C;
			scanf("%d %d %d", &S, &E, &C);
			X[S].push_back(pair<int, vlong>(E, C));
		}
		
		SET(D, -1);
		printf("%lld\n", dp(0));
	}
	return 0;
}
