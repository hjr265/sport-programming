// In the name of Allah, Most Gracious, Most Merciful

// Timus/1471
// Tree
// data structures, trees
// 
// 
// AC (00:32:27 25 Oct 2012)

#pragma comment(linker, "/STACK:16777216")

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define SET(c, v) memset(c, v, sizeof(c))
#define SLC(c, n) c, c+(n)

using namespace std;

template<int N>
class Lca {
	int V[N+2], Vi[N+2], Vl;
	int E[4*N+2], El;
	int H[N+2];
	
public:
	Lca() {
		clear();
	}
	
	void clear() {
		SET(V, -1);
		Vl = 0;
		fill(SLC(E, 4*N+2), 1<<28);
		El = 0;
		SET(H, -1);
	}
	
	void found(int u) {
		if(V[u] == -1)
			V[u] = Vl++, Vi[V[u]] = u;
		u = V[u];
		if(H[u] == -1)
			H[u] = El;
		E[2*N+(El++)] = u;
	}
	
	void build() {
		for(int i = 2*N-1; i; --i)
			E[i] = min(E[2*i], E[2*i+1]);
	}
	
	int ancestor(int u, int v) {
		int l = H[V[u]], h = H[V[v]];
		if(l > h)
			swap(l, h);
		int r = 1<<28;
		for(l += 2*N, h += 2*N+1; l < h; l /= 2, h /= 2) {
			if(l&1)
				r = min(r, E[l++]);
			if(h&1)
				r = min(r, E[--h]);
		}
		return Vi[r];
	}
};

struct Edge {
	int u, v, w;
	
	Edge(int u_, int v_, int w_) : u(u_), v(v_), w(w_) {}
};

vector<Edge> E[50002];
int C[50002];
Lca<50002> L;

void dfs(int u, int d) {
	C[u] = d;
	L.found(u);
	for(int i = 0; i < E[u].size(); ++i) {
		int v = E[u][i].v;
		if(C[v] == -1) {
			dfs(v, d+E[u][i].w);
			L.found(u);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n-1; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		E[u].push_back(Edge(u, v, w));
		E[v].push_back(Edge(v, u, w));
	}
	
	SET(C, -1);
	dfs(0, 0);
	L.build();
	
	int m;
	scanf("%d", &m);
	while(m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", C[u]+C[v]-2*C[L.ancestor(u, v)]);
	}
	return 0;
}
