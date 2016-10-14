// In the name of Allah, Most Gracious, Most Merciful

// SPOJ/BENEFACT
// The Benefactor
// dfs and similar
// 
// 
// AC (2012-11-24 19:12:10)

#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

#define SET(c, v) memset(c, v, sizeof(c))

using namespace std;

typedef long long vlong;

struct Edge {
	int u, v;
	vlong w;
	
	Edge(int u_, int v_, vlong w_) : u(u_), v(v_), w(w_) {}
};

vector<Edge> E[50005];
vlong D[50005];

pair<int, vlong> bfs(int s) {
	pair<int, vlong> R(s, 0);
	SET(D, -1);
	queue<int> Q;
	D[s] = 0;
	Q.push(s);
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		if(D[u] > R.second)
			R = pair<int, vlong>(u, D[u]);
		for(int i = 0; i < E[u].size(); ++i) {
			Edge e = E[u][i];
			if(D[e.v] == -1) {
				D[e.v] = D[u]+e.w;
				Q.push(e.v);
			}
		}
	}
	return R;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		for(int i = 0; i < 50005; ++i)
			E[i].clear();
		
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n-1; ++i) {
			int a, b;
			vlong l;
			scanf("%d %d %lld", &a, &b, &l);
			E[a].push_back(Edge(a, b, l));
			E[b].push_back(Edge(b, a, l));
		}
		
		pair<int, vlong> r = bfs(bfs(1).first);
		printf("%lld\n", r.second);
	}
	return 0;
}
