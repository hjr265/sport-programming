// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1111
// Best Picnic Ever
// dfs and similar
// 
// 
// AC (2011-09-12 18:25:56)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

char g[1005][1005];
char r[1005];
int h[105];

void dfs(int N, int k, int u) {
	++r[u];
	for(int v = 1; v <= N; ++v) if(g[u][v] == 1 && r[v] <= k)
		dfs(N, k, v);
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		CLR(g);
		int K, N, M;
		scanf("%d %d %d", &K, &N, &M);
		for(int i = 0; i < K; ++i)
			scanf("%d", &h[i]);
		while(M--) {
			int u, v;
			scanf("%d %d", &u, &v);
			g[u][v] = 1;
		}
		CLR(r);
		for(int i = 0; i < K; ++i)
			dfs(N, i, h[i]);
		int z = 0;
		for(int u = 1; u <= N; ++u) if(r[u] == K)
			++z;
		printf("Case %d: %d\n", no++, z);
	}
	return 0;
}
