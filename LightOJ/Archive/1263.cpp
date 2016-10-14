// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1263
// Equalizing Money
// dfs and similar
// 
// 
// AC (2011-09-12 19:40:48)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

int t[1005];
char c[1005];
char g[1005][1005];

void dfs(int n, int u, int z, int &k) {
	c[u] = 1;
	k += z - t[u];
	for(int v = 1; v <= n; ++v) if(g[u][v] == 1 && c[v] == 0)
		dfs(n, v, z, k);
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for(int u = 1; u <= n; ++u)
			scanf("%d", &t[u]);
		int s = 0;
		for(int u = 1; u <= n; ++u)
			s += t[u];
		CLR(g);
		for(int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			g[u][v] = g[v][u] = 1;
		}
		CLR(c);
		int k = 0;
		for(int u = 1; u <= n && k == 0; ++u) if(c[u] == 0)
			k = 0, dfs(n, u, s / n, k);
		printf("Case %d: %s\n", no++, k == 0 ? "Yes" : "No");
	}
	return 0;
}
