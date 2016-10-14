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

struct Customer {
	int A, S, X, Y;
};

Customer V[10005];
vector<int> E[10005];
int D[10005];

void dfs(int u, int d) {
	++D[d];
	for(int i = 0; i < E[u].size(); ++i)
		dfs(E[u][i], d+1);
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		for(int i = 0; i < 10005; ++i)
			E[i].clear();
		SET(D, 0);
		
		int N;
		scanf("%d", &N);
		for(int i = 1, X = 0; i <= N; ++i) {
			Customer &C = V[i];
			scanf("%d %d", &C.A, &C.S);
			
			C.X = max(C.A, X);
			C.Y = C.X+C.S;
			X = C.Y;
		}
		
		for(int i = 1, j = 0, X = 0; i <= N; ++i) {
			while(V[i].A >= V[j].Y)
				++j;
			
			E[i == j ? 0 : j].push_back(i);
		}
		
		for(int i = 0; i < E[0].size(); ++i)
			dfs(E[0][i], 0);
		
		
		double X = 0, Y = 1, Z = E[0].size();
		X += 1;
		for(int i = 1; D[i]; ++i) {
			X += (double)D[i]/Z;
			Y += 1;
		}
		printf("Case %d: %0.7lf\n", no++, X/Y);
	}
	return 0;
}
