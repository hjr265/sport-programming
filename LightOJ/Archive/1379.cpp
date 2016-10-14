// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1379
// Toll Management
// shortest paths
// 
// 
// AC (2012-03-08 22:22:03)

#include <cstdio>
#include <cstring>
#include <set>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

struct Edge {
	int v, w;
	
	Edge(int v_, int w_) : v(v_), w(w_) {}
};

vector<Edge> E1[10002], E2[10002];
int D1[10002], D2[10002];

void dijkstra(int s, const vector<Edge> E[], int D[]) {
	set<pair<int, int> > q;
	D[s] = 0;
	q.insert(pair<int, int>(0, s));
	while(!q.empty()) {
		int u = q.begin()->second;
		q.erase(q.begin());
		for(int i = 0; i < E[u].size(); ++i) {
			int v = E[u][i].v, w = E[u][i].w;
			if(D[v] == -1 || D[u]+w < D[v]) {
				D[v] = D[u]+w;
				q.insert(pair<int, int>(D[u]+w, v));
			}
		}
	}
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N, M, s, t, p;
		scanf("%d %d %d %d %d", &N, &M, &s, &t, &p);
		for(int i = 0; i < 10002; ++i) {
			E1[i].clear();
			E2[i].clear();
		}
		while(M--) {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			E1[u].push_back(Edge(v, c));
			E2[v].push_back(Edge(u, c));
		}
		SET(D1);
		dijkstra(s, E1, D1);
		SET(D2);
		dijkstra(t, E2, D2);
		int r = -1;
		for(int u = 1; u <= N; ++u) if(D1[u] != -1) {
			for(int i = 0; i < E1[u].size(); ++i) {
				int v = E1[u][i].v, w = E1[u][i].w;
				if(D2[v] != -1 && D1[u]+w+D2[v] <= p)
					r = max(r, w);
			}
		}
		printf("Case %d: %d\n", no++, r);
	}
	return 0;
}
