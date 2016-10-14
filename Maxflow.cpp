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

template<class FT, int N>
class Maxflow {
	struct Edge {
		int u, v;
		FT c, f;
		int b;
		
		Edge(int u_, int v_, FT c_, int b_) : u(u_), v(v_), c(c_), f(0), b(b_) {}
	};
	
	vector<Edge> E[N];
	int P[N];
	FT M[N];
	
	FT augpath() {
		SET(P, -1);
		P[0] = -2;
		M[0] = 1<<30;
		queue<int> q;
		q.push(0);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int i = 0; i < E[u].size(); ++i) {
				Edge e = E[u][i];
				if(e.c-e.f > 0 && P[e.v] == -1) {
					P[e.v] = u;
					M[e.v] = min(M[u], e.c-e.f);
					if(e.v == N-1)
						return M[e.v];
					q.push(e.v);
				}
			}
		}
		return 0;
	}
	
public:
	Maxflow() {
		clear();
	}
	
	void clear() {
		for(int i = 0; i < N; ++i)
			E[i].clear();
	}
	
	void addedge(int u, int v, FT c) {
		E[u].push_back(Edge(u, v, c, E[v].size()));
		E[v].push_back(Edge(v, u, c, E[u].size()-1));
	}
	
	FT maxflow() {
		int f = 0;
		while(true) {
			int m = augpath();
			if(m == 0)
				break;
			f = f+m;
			int v = N-1;
			while(v != 0) {
				int u = P[v];
				for(int i = 0; i < E[u].size(); ++i) if(E[u][i].v == v) {
					E[u][i].f += m;
					E[v][E[u][i].b].f -= m;
					break;
				}
				v = u;
			}
		}
		return f;
	}
};

int main() {
	
	return 0;
}
