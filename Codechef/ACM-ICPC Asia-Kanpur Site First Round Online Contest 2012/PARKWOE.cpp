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

int G[1002][1002];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		for(int i = 0; i < 1002; ++i)
			fill(SLC(G[i], 1002), 2147483647);
		
		int m, n;
		scanf("%d %d", &m, &n);
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j)	
				scanf("%d", &G[i][j]);
		}
		
		int i = 0, j = 0, r = 0;
		while(G[i][j] != 2147483647) {
			if(G[i+1][j] < G[i][j+1])
				++i;
			else
				++j;
			++r;
		}
		
		printf("%d\n", max(r-1, 0));
	}
	return 0;
}
