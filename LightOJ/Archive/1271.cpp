// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1271
// Better Tour
// dfs and similar
// 
// 
// AC (2011-09-12 19:06:19)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

vector<int> g[50005];
int d[50005];
int p[50005];

void printpath(int u) {
	if(p[u] != -1) {
		printpath(p[u]);
		printf(" %d", u);
	} else {
		printf("%d", u);
	}
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int s, t;
		scanf("%d", &s);
		for(int i = 1; i <= 50000; ++i)
			g[i].clear();
		t = s;
		for(int i = 1; i < n; ++i) {
			int v;
			scanf("%d", &v);
			g[t].push_back(v);
			g[v].push_back(t);
			t = v;
		}
		for(int i = 1; i <= 50000; ++i)
			sort(g[i].begin(), g[i].end());
		SET(d);
		queue<int> q;
		d[s] = 0;
		p[s] = -1;
		q.push(s);
		while(!q.empty() && d[t] == -1) {
			int u = q.front();
			q.pop();
			for(int i = 0, l = g[u].size(); i < l; ++i) {
				int v = g[u][i];
				if(d[v] == -1) {
					d[v] = d[u] + 1;
					p[v] = u;
					if(v == t)
						break;
					q.push(v);
				}
			}
		}
		printf("Case %d:\n", no++);
		printpath(t);
		printf("\n");
	}
	return 0;
}
