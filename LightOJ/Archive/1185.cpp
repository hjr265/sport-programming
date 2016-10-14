// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1185
// Escape
// dfs and similar
// 
// 
// AC (2012-03-05 16:43:38)

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

vector<int> E[102];
bool C[102][2];

int bfs() {
	CLR(C);
	queue<pair<int, int> > q;
	for(int i = 0; i < E[1].size(); ++i) {
		q.push(pair<int, int>(E[1][i], 0));
		C[E[1][i]][0] = true;
	}
	int r = 0;
	while(!q.empty()) {
		int u = q.front().first;
		int w = q.front().second;
		q.pop();
		if(w)
			++r;
		for(int i = 0; i < E[u].size(); ++i) {
			int v = E[u][i];
			if(!C[v][1-w]) {
				C[v][1-w] = true;
				q.push(pair<int, int>(v, 1-w));
			}
		}
	}
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < 102; ++i)
			E[i].clear();
		while(m--) {
			int a, b;
			scanf("%d %d", &a, &b);
			E[a].push_back(b);
			E[b].push_back(a);
		}
		printf("Case %d: %d\n", no++, bfs());
	}
	return 0;
}
