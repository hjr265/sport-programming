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

struct Edge {
	int u, v;
	double w;
	
	Edge(int u_, int v_, double w_) : u(u_), v(v_), w(w_) {}
};

vector<Edge> E[5002];
double D[5002];

void dijkstra(int s) {
	fill(SLC(D, 5002), 1e20);
	set<pair<double, int> > Q;
	D[s] = 1e20;
	Q.insert(pair<double, int>(1e20, s));
	while(!Q.empty()) {
		int u = Q.begin()->second;
		Q.erase(Q.begin());
		for(int i = 0; i < E[u].size(); ++i) {
			Edge e = E[u][i];
			if(D[e.v] > 1e19 || min(D[u], e.w) > D[e.v]) {
				D[e.v] = min(D[u], e.w);
				Q.insert(pair<double, int>(D[e.v], e.v));
			}
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		for(int i = 0; i < 5002; ++i)
			E[i].clear();
		
		int N;
		scanf("%d", &N);
		
		int u, v;
		double w;
		while(scanf("%d %d %lf", &u, &v, &w) == 3 && (u != -1 || v != -1)) {
			E[u].push_back(Edge(u, v, w));
			E[v].push_back(Edge(v, u, w));
		}
		
		dijkstra(1);
		
		printf("%0.7lf\n", D[N]);
	}
	return 0;
}
