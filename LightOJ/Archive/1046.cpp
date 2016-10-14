// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1046
// Rider
// dfs and similar
// 
// 
// AC (2011-12-10 16:21:52)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

char g[12][12];
bool x[12][12];
int y[12][12];
int d[12][12];
int r[12][12];

void bfs(int m, int n, int K, pair<int, int> s) {
	CLR(x);
	queue<pair<int, int> > q;
	q.push(s);
	x[s.first][s.second] = true;
	y[s.first][s.second] = 0;
	r[s.first][s.second] += 1;
	while(!q.empty()) {
		pair<int, int> u = q.front();
		q.pop();
		const int t[][2] = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
		for(int i = 0; i < 8; ++i) {
			for(int j = 1; j <= 1; ++j) {
				pair<int, int> v(u.first+t[i][0]*j, u.second+t[i][1]*j);
				if(v.first >= 0 && v.first < m && v.second >= 0 && v.second < n && !x[v.first][v.second]) {
					x[v.first][v.second] = true;
					y[v.first][v.second] = y[u.first][u.second]+1;
					r[v.first][v.second] += 1;
					q.push(v);
				}
			}
		}
	}
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j)
			d[i][j] += (y[i][j]+K-1)/K;
	}
}

int ans(int m, int n, int t) {
	int z = 1<<28;
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) if(r[i][j] == t)
			z = min(z, d[i][j]);
	}
	return z == 1<<28 ? -1 : z;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int m, n;
		scanf("%d %d", &m, &n);
		for(int i = 0; i < m; ++i)
			scanf("%s", g[i]);
		CLR(r);
		CLR(d);
		int t = 0;
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) if(g[i][j] != '.') {
				bfs(m, n, g[i][j]-'0', pair<int, int>(i, j));
				t += 1;
			}
		}
		printf("Case %d: %d\n", no++, ans(m, n, t));
	}
	return 0;
}
