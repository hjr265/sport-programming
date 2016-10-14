// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1063
// Ant Hills
// dfs and similar
// 
// 
// AC (2011-09-18 17:53:23)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

vector<int> g[10005];
int c[10005];
int d[10005];
int e[10005];
int l[10005];
int q;
set<int> z;

void artp(int u) {
	l[u] = d[u] = q++;
	for(int i = 0, m = g[u].size(); i < m; ++i) {
		int v = g[u][i];
		if(d[v] == -1) {
			e[v] = e[u] + 1;
			++c[u];
			artp(v);
			l[u] = min(l[u], l[v]);
			if(d[u] == 0) {
				if(c[u] >= 2)
					z.insert(u);
			} else if(l[v] >= d[u]) {
				z.insert(u);
			}
		} else if(e[v] < e[u] - 1) {
			l[u] = min(l[u], d[v]);
		}
	}
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for(int u = 1; u <= n; ++u)
			g[u].clear();
		for(int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		CLR(c);
		SET(d);
		CLR(e);
		CLR(l);
		q = 0;
		z.clear();
		for(int u = 1; u <= n; ++u) if(d[u] == -1)
			artp(u);
		printf("Case %d: %d\n", no++, z.size());
		
	}
	return 0;
}
