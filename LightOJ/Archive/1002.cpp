// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1002
// Country Roads
// mst, *shortest paths
// 
// 
// AC (2011-07-27 20:46:39)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

struct Edge {
	int v, w;
	
	Edge() {}
	
	Edge(int v_, int w_) : v(v_), w(w_) {}
};

vector<Edge> E[502];
int d[502];

void dijkstra(int s) {
	SET(d);
	set<pair<int, int> > q;
	d[s] = 0;
	q.insert(pair<int, int>(0, s));
	while(!q.empty()) {
		int u = q.begin()->second;
		q.erase(q.begin());
		for(int i = 0; i < E[u].size(); ++i) {
			Edge e = E[u][i];
			if(d[e.v] == -1 || max(d[u], e.w) < d[e.v]) {
				d[e.v] = max(d[u], e.w);
				q.insert(pair<int, int>(d[e.v], e.v));
			}
		}
	}
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for(int u = 0; u < 502; ++u)
			E[u].clear();
		while(m--) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			E[u].push_back(Edge(v, w));
			E[v].push_back(Edge(u, w));
		}
		int t;
		scanf("%d", &t);
		dijkstra(t);
		printf("Case %d:\n", no++);
		for(int u = 0; u < n; ++u) {
			if(d[u] == -1)
				printf("Impossible\n");
			else
				printf("%d\n", d[u]);
		}
	}
	return 0;
}
