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

int N;
char G[1002][1002];
char GT[1002][1002];
char T[1002][1002];
char R[4000002];

void rotate() {
	memcpy(GT, G, sizeof(G));
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j)
			G[j][N-i-1] = GT[i][j];
	}
}

int main() {
	while(scanf("%d", &N) == 1 && N != 0) {
		for(int i = 0; i < N; ++i)
			scanf("%s", G[i]);
		for(int i = 0; i < N; ++i)
			scanf("%s", T[i]);
		
		int H = 0;
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) if(G[i][j] == 'O')
				++H;	
		}
		
		for(int k = 0; k < 4*H; ) {
			for(int i = 0; i < N; ++i) {
				for(int j = 0; j < N; ++j) if(G[i][j] == 'O')
					R[k++] = T[i][j];
			}
			rotate();
		}
		R[H*4] = '\0';
		
		printf("%s\n", R);
	}
	return 0;
}
