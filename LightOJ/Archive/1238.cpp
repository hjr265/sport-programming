// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1238
// Power Puff Girls
// dfs and similar
// 
// 
// AC (2011-09-12 11:02:43)

#include <cstdio>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

char g[22][22];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int m, n;
		scanf("%d %d\n", &m, &n);
		for(int i = 0; i < m; ++i)
			gets(g[i]);
		map<pair<int, int>, int> d;
		queue<pair<int, int> > q;
		pair<int, int> s;
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				if(g[i][j] == 'h')
					s.first = i, s.second = j;
				d[pair<int, int>(i, j)] = 1<<28;
			}
		}
		d[s] = 0;
		q.push(s);
		int z = 0;
		while(!q.empty()) {
			pair<int, int> u = q.front();
			q.pop();
			const int x[][2] = {
				{0, -1},
				{0, 1},
				{-1, 0},
				{1, 0}
			};
			for(int i = 0; i < 4; ++i) {
				pair<int, int> v(u.first + x[i][0], u.second + x[i][1]);
				if(g[v.first][v.second] != '#' && g[v.first][v.second] != 'm' && d[v] == 1<<28) {
					d[v] = d[u] + 1;
					q.push(v);
					if(g[v.first][v.second] == 'a' || g[v.first][v.second] == 'b' || g[v.first][v.second] == 'c')
						z = max(z, d[v]);
				}
			}
		}
		printf("Case %d: %d\n", no++, z);
	}
	return 0;
}
