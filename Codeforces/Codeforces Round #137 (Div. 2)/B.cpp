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

int R[1002], C[1002], G[1002][1002];

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j)
			scanf("%d", &G[i][j]);
	}
	
	for(int i = 0; i < 1002; ++i)
		R[i] = C[i] = i;
	
	while(k--) {
		char s[4];
		int x, y;
		scanf("%s %d %d", s, &x, &y);
		--x, --y;
		
		switch(s[0]) {
		case 'g':
			printf("%d\n", G[R[x]][C[y]]);
			break;
		case 'r':
			swap(R[x], R[y]);
			break;
		case 'c':
			swap(C[x], C[y]);
			break;
		}
	}
	return 0;
}
