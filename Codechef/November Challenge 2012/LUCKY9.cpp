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
const vlong MOD = 1000000007;

enum {
	
};

int G[5005][5005];
char S[5005];

int main() {
	for(int i = 1; i <= 5000; ++i)
		G[0][i] = G[i][0] = 1;
	G[1][1] = 1;
	for(int i = 1; i <= 5000; ++i) {
		for(int j = 1; j <= 5000; ++j) if(i != 1 || j != 1) {
			G[i][j] = G[i-1][j]+G[i][j-1];
			while(G[i][j] >= MOD)
				G[i][j] -= MOD;
		}
	}
	
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", S);
		int C[10];
		SET(C, 0);
		for(int i = 0; S[i]; ++i)
			++C[S[i]-'0'];
		printf("%d\n", G[C[4]][C[7]]);
	}
	return 0;
}
