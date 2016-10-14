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

int G[205][205];
int S[205][205];

bool move(int R, int C, int &r, int &c, int K, int x) {
	switch(x) {
	case 0:
		if(r-K < 1 || S[r-1][c]-S[r-1][c-1]-S[r-K-1][c]+S[r-K-1][c-1] > 0)
			return false;
		r -= K;
		break;
	case 1:
		if(c+K > C || S[r][c+K]-S[r][c]-S[r-1][c+K]+S[r-1][c] > 0)
			return false;
		c += K;
		break;
	case 2:
		if(r+K > R || S[r+K][c]-S[r+K][c-1]-S[r][c]+S[r][c-1] > 0)
			return false;
		r += K;
		break;
	case 3:
		if(c-K < 1 || S[r][c-1]-S[r-1][c-1]-S[r][c-K-1]+S[r-1][c-K-1] > 0)
			return false;
		c -= K;
		break;
	}
	return true;
}

void turn(int &x) {
	x = (x+1)%4;
}

bool bfs(int R, int C, int r, int c, int K, int x) {
	--K;
	if(!move(R, C, r, c, K, x))
		return false;
	turn(x);
	while(K > 0) {
		if(!move(R, C, r, c, K, x))
			return false;
		turn(x);
		if(!move(R, C, r, c, K, x))
			return false;
		turn(x);
		K = K-2;
	}
	return true;
	
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int R, C, K, B;
		scanf("%d %d %d %d", &R, &C, &K, &B);
		SET(G, 0);
		for(int i = 0; i < B; ++i) {
			int r, c;
			scanf("%d %d", &r, &c);
			G[r][c] = 1;
		}
		SET(S, 0);
		for(int r = 1; r <= R; ++r) {
			for(int c = 1; c <= C; ++c)
				S[r][c] = S[r][c-1]+S[r-1][c]-S[r-1][c-1]+G[r][c];
		}
		
		int z = 0;
		for(int r = 1; r <= R; ++r) {
			for(int c = 1; c <= C; ++c) {
				int x[] = {0, 2, 1, 3};
				for(int i = 0; i < 4; ++i) if(G[r][c] == 0 && bfs(R, C, r, c, K, x[i]))
					++z;
			}
		}
		printf("Case %d: %d\n", no++, z);
	}
	return 0;
}
