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

template<class TF, class TC, int N, int s, int t>
class Mincostmaxflow {
	struct Edge {
		int u, v;
		TF f, c;
		TC w;
		int r;
		
		Edge(int u_, int v_, TF f_, TF c_, TW w_, int r_) : u(u_), v(v_), f(f_), c(c_), w(w_), r(r_) {}
	};
	
	int 
	vector<Edge> E[N];
	int P[N];
	int C[N];
	
	TF augpath() {
		C[s] = -1;
		P[s] = -1;
	}

public:
	Mincostmaxflow() {
		clear();
	}
	
	void clear() {
		for(int i = 0; i < N; ++i)
			E[i].clear();
	}
	
	void addedge(int u, int v, TF c, TC w) {
		Edge a(u, v, 0, c, w, E[v].size()), b(v, u, 0, 0, -w, E[u].size());
		E[u].push_back(a);
		E[v].push_back(b);
	}
	
	pair<TF, TC> flow() {
		pair<TF, TC> r;
		while(true) {
			TF m = augpath();
			if(!m)
				break;
			r.first += m;
			int u = P[t], v = t;
			while(u != -1) {
				for(int i = 0; i < E[u].size(); ++i) if(E[u][i].v == v) {
					E[u][i].f += m;
					E[v][E[u][i].r].f -= m;
					break;
				}
				v = u, u = P[v];
			}
		}
	}
};

string s[102];
int a[102];
Mincostmaxflow<int, int, 10002, 0, 10000> MCMF;

int main() {
	string t;
	cin >> t;
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i];
		cin >> a[i];
	}
	
	pair<int, int> r = MCMF.flow();
	printf("%d\n", r.second == t.size() ? r.first : -1);
	return 0;
}
