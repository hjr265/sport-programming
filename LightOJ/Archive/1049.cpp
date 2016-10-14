// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1049
// One Way Roads
// dfs and similar
// 
// 
// AC (2012-05-02 10:24:00)

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
	int v, w;
	
	Edge(int v_, int w_) : v(v_), w(w_) {}
};

vector<Edge> E[102];

int dfs(int u, int p) {
	if(u == 1)
		return 0;
	int r = 0;
	for(int i = 0; i < E[u].size(); ++i) if(E[u][i].v != p)
		r += dfs(E[u][i].v, u)+E[u][i].w;
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < 102; ++i)
			E[i].clear();
		for(int i = 0; i < n; ++i) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			E[a].push_back(Edge(b, 0));
			E[b].push_back(Edge(a, c));
		}
		printf("Case %d: %d\n", no++, min(dfs(E[1][0].v, 1)+E[1][0].w, dfs(E[1][1].v, 1)+E[1][1].w));
	}
	return 0;
}
