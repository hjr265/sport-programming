// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1174
// Commandos
// dfs and similar, *shortest paths
// 
// 
// AC (2012-01-09 12:12:06)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

int N, R;
int g[105][105];
int s, d;

void flwa() {
	for(int x = 0; x < N; ++x) {
		for(int u = 0; u < N; ++u) {
			for(int v = 0; v < N; ++v)
				g[u][v] = min(g[u][v], g[u][x]+g[x][v]);
		}
	}
}

int ans() {
	flwa();
	int r = 0;
	for(int x = 0; x < N; ++x) if(g[s][x]+g[x][d] < 50000)
		r = max(r, g[s][x]+g[x][d]);
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		scanf("%d", &R);
		CLR(g);
		for(int u = 0; u < N; ++u) {
			for(int v = 0; v < N; ++v) if(u != v)
				g[u][v] = 50000;
		}
		for(int i = 0; i < R; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			g[u][v] = g[v][u] = 1;
		}
		scanf("%d %d", &s, &d);
		printf("Case %d: %d\n", no++, ans());
	}
	return 0;
}
