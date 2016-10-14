// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1009
// Back to Underworld
// dfs and similar
// 
// 
// AC (2011-10-31 22:51:58)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

vector<int> g[20005];
char m[20005];

int c[2];

void dfs(int u, int x) {
	for(int i = 0, l = g[u].size(); i < l; ++i) if(!m[g[u][i]]) {
		m[g[u][i]] = 1;
		++c[!x];
		dfs(g[u][i], !x);
	}
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < 20005; ++i)
			g[i].clear();
		CLR(m);
		for(int i = 0; i < n; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
			m[u] = 0;
			m[v] = 0;
		}
		int r = 0;
		for(int u = 1; u < 20005; ++u) if(!m[u]) {
			CLR(c);
			m[u] = 1;
			++c[0];
			dfs(u, 0);
			r += max(c[0], c[1]);
		}
		printf("Case %d: %d\n", no++, r);
	}
	return 0;
}
