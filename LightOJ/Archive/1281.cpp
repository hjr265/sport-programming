// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1281
// New Traffic System
// shortest paths
// 
// 
// AC (2012-05-01 12:23:03)

#include <cstdio>
#include <cstring>
#include <set>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

struct Edge {
	int v, w0, w1;
	
	Edge() {}
	
	Edge(int v_, int w0_, int w1_) : v(v_), w0(w0_), w1(w1_) {}
};

vector<Edge> E[10002];
int d[10002][12];

int dijkstra(int n, int l) {
	SET(d);
	set<pair<int, pair<int, int> > > q;
	d[0][0] = 0;
	q.insert(pair<int, pair<int, int> >(0, pair<int, int>(0, 0)));
	while(!q.empty()) {
		int u = q.begin()->second.second, c = q.begin()->second.first;
		q.erase(q.begin());
		if(u == n-1)
			return d[u][c];
		for(int i = 0; i < E[u].size(); ++i) {
			Edge e = E[u][i];
			if((d[e.v][c+e.w1] == -1 || d[u][c]+e.w0 < d[e.v][c+e.w1]) && c+e.w1 <= l) {
				d[e.v][c+e.w1] = d[u][c]+e.w0;
				q.insert(pair<int, pair<int, int> >(d[e.v][c+e.w1], pair<int, int>(c+e.w1, e.v)));
			}
		}
	}
	return -1;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, m, k, d;
		scanf("%d %d %d %d", &n, &m, &k, &d);
		for(int u = 0; u < 10002; ++u)
			E[u].clear();
		while(m--) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			E[u].push_back(Edge(v, w, 0));
		}
		while(k--) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			E[u].push_back(Edge(v, w, 1));
		}
		int r = dijkstra(n, d);
		printf("Case %d: ", no++);
		if(r == -1)
			printf("Impossible\n");
		else
			printf("%d\n", r);
	}
	return 0;
}
