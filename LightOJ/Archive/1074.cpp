// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1074
// Extended Traffic
// shortest paths
// 
// 
// AC (2011-09-17 20:58:23)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long vlong;

struct Edge {
	int u, v;
	vlong w;
};

vector<Edge> g;
vlong b[205];
vlong d[205];

void befo(int n, int m, int s) {
	for(int u = 1; u <= n; ++u)
		d[u] = 1LL<<60;
	d[s] = 0;
	for(int i = 0; i < n - 1; ++i)
		for(int j = 0; j < m; ++j) if(d[g[j].u] != 1LL<<60)
			d[g[j].v] = min(d[g[j].v], d[g[j].u] + g[j].w);
	for(int j = 0; j < m; ++j)
		if(d[g[j].u] + g[j].w < d[g[j].v])
			d[g[j].v] = -1;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int u = 1; u <= n; ++u)
			scanf("%lld", &b[u]);
		int m;
		scanf("%d", &m);
		g.clear();
		for(int i = 0; i < m; ++i) {
			Edge e;
			scanf("%d %d", &e.u, &e.v);
			e.w = (b[e.v] - b[e.u]) * (b[e.v] - b[e.u]) * (b[e.v] - b[e.u]);
			g.push_back(e);
		}
		befo(n, m, 1);
		int q;
		scanf("%d", &q);
		printf("Case %d:\n", no++);
		while(q--) {
			int v;
			scanf("%d", &v);
			if(d[v] < 3 || d[v] == 1LL<<60)
				printf("?\n");
			else
				printf("%lld\n", d[v]);
		}
	}
	return 0;
}
