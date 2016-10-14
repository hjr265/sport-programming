// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1257
// Farthest Nodes in a Tree (II)
// *dfs and similar, dp
// 
// 
// AC (2012-03-05 17:12:25)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

struct Edge {
	int v, w;
	
	Edge(int v_, int w_) : v(v_), w(w_) {}
};

vector<Edge> E[30002];
int D[30002], F[30002];

void bfs(int s, int t) {
	SET(D);
	queue<int> q;
	D[s] = 0;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		F[u] = max(F[u], D[u]);
		for(int i = 0; i < E[u].size(); ++i) {
			int v = E[u][i].v, w = E[u][i].w;
			if(D[v] == -1) {
				D[v] = D[u]+w;
				q.push(v);
			}
		}
	}
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d\n", &n);
		for(int i = 0; i < 30002; ++i)
			E[i].clear();
		for(int i = 0; i < n-1; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			E[u].push_back(Edge(v, w));
			E[v].push_back(Edge(u, w));
		}
		CLR(F);
		bfs(0, -1);
		int s = 0;
		for(int u = 0; u < n; ++u) if(D[u] >= D[s])
			s = u;
		bfs(s, -1);
		int t = s;
		for(int u = 0; u < n; ++u) if(D[u] >= D[t])
			t = u;
		bfs(t, -1);
		printf("Case %d:\n", no++);
		for(int u = 0; u < n; ++u)
			printf("%d\n", F[u]);
	}
	return 0;
}
