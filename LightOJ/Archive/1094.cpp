// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1094
// Farthest Nodes in a Tree
// dfs and similar
// 
// 
// AC (2011-12-08 01:50:56)

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

struct Edge {
	int v, w;
};

vector<Edge> E[30005];
int d[30005];

int bfs(int s) {
	SET(d);
	queue<int> q;
	q.push(s);
	d[s] = 0;
	int z = s;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0, l = E[u].size(); i < l; ++i) if(d[E[u][i].v] == -1) {
			d[E[u][i].v] = d[u]+E[u][i].w;
			if(d[E[u][i].v] > d[z])
				z = E[u][i].v;
			q.push(E[u][i].v);
		}
	}
	return z;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			E[i].clear();
		for(int i = 0; i < n-1; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			E[u].push_back((Edge){v, w});
			E[v].push_back((Edge){u, w});
		}
		printf("Case %d: %d\n", no++, d[bfs(bfs(0))]);
	}
	return 0;
}
