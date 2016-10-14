// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1254
// Prison Break
// shortest paths
// 
// 
// AC (2012-05-01 15:26:23)

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define CLR(c) memset(c, 0, sizeof(c))
#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

struct Edge {
	int v, w;
	
	Edge() {}
	
	Edge(int v_, int w_) : v(v_), w(w_) {}
};

vector<Edge> E[102];
int P[102];
int d[102][102];
bool z[102][102];

int dijkstra(int c, int s, int t) {
	SET(d);
	CLR(z);
	priority_queue<pair<int, pair<int, int> > > q;
	d[s][0] = 0;
	q.push(pair<int, pair<int, int> >(0, pair<int, int>(0, s)));
	while(!q.empty()) {
		int u = q.top().second.second, f = q.top().second.first;
		q.pop();
		if(u == t)
			return d[u][f];
		if(z[u][f])
			continue;
		for(int i = 0; i < E[u].size(); ++i) {
			Edge e = E[u][i];
			for(int j = max(0, e.w-f); j <= c-f; ++j) if(f+j-e.w >= 0 && !z[e.v][f+j-e.w] && (d[e.v][f+j-e.w] == -1 || d[u][f]+j*P[u] < d[e.v][f+j-e.w])) {
				d[e.v][f+j-e.w] = d[u][f]+j*P[u];
				q.push(pair<int, pair<int, int> >(-(d[u][f]+j*P[u]), pair<int, int>(f+j-e.w, e.v)));
			}
		}
		z[u][f] = true;
	}
	return -1;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; ++i)
			scanf("%d", &P[i]);
		for(int u = 0; u < 102; ++u)
			E[u].clear();
		while(m--) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			E[u].push_back(Edge(v, w));
			E[v].push_back(Edge(u, w));
		}
		printf("Case %d:\n", no++);
		int q;
		scanf("%d", &q);
		while(q--) {
			int c, s, t;
			scanf("%d %d %d", &c, &s, &t);
			int r = dijkstra(c, s, t);
			if(r == -1)
				printf("impossible\n");
			else
				printf("%d\n", r);
		}
	}
	return 0;
}
