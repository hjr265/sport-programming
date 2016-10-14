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

struct Point {
	vlong x, y;
};

int N, S, F;
Point V[1002];
vector<int> E[1002];
int D[1002];

int bfs() {
	SET(D, -1);
	queue<int> Q;
	D[S] = 0;
	Q.push(S);
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for(int i = 0; i < E[u].size(); ++i) {
			int v = E[u][i];
			if(D[v] == -1) {
				D[v] = D[u]+1;
				if(v == F)
					return D[v];
				Q.push(v);
			}
		}
	}
	return -1;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		for(int i = 0; i < 1002; ++i)
			E[i].clear();
		
		double L1, L2;
		scanf("%d %d %d %lf %lf", &N, &S, &F, &L1, &L2);
		for(int i = 1; i <= N; ++i)
			scanf("%lld %lld", &V[i].x, &V[i].y);
			
		for(int i = 1; i <= N; ++i) {
			for(int j = i+1; j <= N; ++j) if((V[i].x-V[j].x)*(V[i].x-V[j].x)+(V[i].y-V[j].y)*(V[i].y-V[j].y) <= (L1+L2)*(L1+L2)+EPS) {
				E[i].push_back(j);
				E[j].push_back(i);
			}
		}
		
		int r = bfs();
		if(r < 0)
			printf("Impossible\n");
		else
			printf("%d\n", r);
	}
	return 0;
}
