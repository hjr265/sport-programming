// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1108
// Instant View of Big Bang
// shortest paths
// 
// 
// AC (2012-03-12 00:46:11)

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define CLR(c) memset(c, 0, sizeof(c))
#define SLC(c, n) c, c+n

struct Edge {
	int v, w;
	
	Edge(int v_, int w_) : v(v_), w(w_) {
		
	}
};

int n;
vector<Edge> E[1002];
int d[1002];
bool r[1002];

void dfs(int u) {
	if(r[u])
		return;
	r[u] = true;
	for(int i = 0; i < E[u].size(); ++i)
		dfs(E[u][i].v);
}

void befo() {
	fill(SLC(d, 1002), 1<<30);
	d[0] = 0;
	for(int i = 0; i < n-1; ++i) {
		for(int u = 0; u < n; ++u) {
			for(int j = 0; j < E[u].size(); ++j) {
				int v = E[u][j].v, w = E[u][j].w;
				if(d[u]+w < d[v])
					d[v] = d[u]+w;
			}
		}
	}
	CLR(r);
	for(int u = 0; u < n; ++u) {
		for(int j = 0; j < E[u].size(); ++j) {
			int v = E[u][j].v, w = E[u][j].w;
			if(d[u] != 1<<30 && d[u]+w < d[v])
				dfs(u);
		}
	}
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int m;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < 1002; ++i)
			E[i].clear();
		while(m--) {
			int x, y, t;
			scanf("%d %d %d", &x, &y, &t);
			E[y].push_back(Edge(x, t));
		}
		printf("Case %d:", no++);
		befo();
		bool f = false;
		for(int u = 0; u < n; ++u) if(r[u]) {
			printf(" %d", u);
			f = true;
		}
		if(!f)
			printf(" impossible");
		printf("\n");
	}
	return 0;
}
