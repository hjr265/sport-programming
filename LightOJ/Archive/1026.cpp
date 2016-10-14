// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1026
// Critical Links
// dfs and similar
// 
// 
// AC (2012-02-03 12:07:24)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))
#define ALL(c) c.begin(), c.end()

using namespace std;

vector<int> g[10002];
vector<pair<int, int> > r;
int c[10002], f[10002];
int t;

void dfs(int u, int p = -1) {
	if(c[u] != -1)
		return;
	c[u] = f[u] = t++;
	for(int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if(v == p)
			continue;
		if(c[v] != -1) {
			f[u] = min(f[u], f[v]);
		} else {
			dfs(v, u);
			if(f[v] > c[u])
				r.push_back(pair<int, int>(min(u, v), max(u, v)));
		}
	}
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int u = 0; u < n; ++u)
			g[u].clear();
		for(int i = 0; i < n; ++i) {
			int u, k;
			scanf("%d (%d)", &u, &k);
			while(k--) {
				int v;
				scanf("%d", &v);
				g[u].push_back(v);
				g[v].push_back(u);
			}
		}
		r.clear();
		SET(c);
		CLR(f);
		for(int u = 0; u < n; ++u) if(c[u] == -1)
			dfs(u);
		printf("Case %d:\n", no++);
		printf("%d critical links\n", r.size());
		sort(ALL(r));
		for(int i = 0; i < r.size(); ++i)
			printf("%d - %d\n", r[i].first, r[i].second);
	}
	return 0;
}
