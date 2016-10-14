// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1377
// Blade and Sword
// dfs and similar
// 
// 
// AC (2012-01-07 23:38:05)

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

int m, n;
char g[205][205];
vector<pair<int, int> > t;
pair<int, int> s;
pair<int, int> e;
int d[205][205];

int bfs(pair<int, int> s, pair<int, int> e) {
	SET(d);
	queue<pair<int, int> > q;
	d[s.first][s.second] = 0;
	q.push(s);
	while(!q.empty()) {
		pair<int, int> u = q.front();
		q.pop();
		const int x[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		for(int i = 0; i < 4; ++i) {
			pair<int, int> v(u.first+x[i][0], u.second+x[i][1]);
			if(g[v.first][v.second] != '#' && d[v.first][v.second] == -1) {
				if(v == e)
					return d[u.first][u.second]+1;
				if(g[v.first][v.second] == '*') {
					if(t.size() > 1) {
						for(int k = 0; k < t.size(); ++k) if(t[k] != v && d[t[k].first][t[k].second] == -1) {
							d[t[k].first][t[k].second] = d[u.first][u.second]+2;
							q.push(t[k]);
						}
						d[v.first][v.second] = d[u.first][u.second]+3;
						q.push(v);
					}
				} else {
					d[v.first][v.second] = d[u.first][u.second]+1;
					q.push(v);
				}
			}
		}
	}
	return -1;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &m, &n);
		t.clear();
		for(int i = 0; i < m; ++i) {
			scanf("%s", g[i]);
			for(int j = 0; j < n; ++j) switch(g[i][j]) {
			case '*':
				t.push_back(pair<int, int>(i, j));
				break;
			case 'P':
				s = pair<int, int>(i, j);
				break;
			case 'D':
				e = pair<int, int>(i, j);
				break;
			}
		}
		int r = bfs(s, e);
		printf("Case %d: ", no++);
		if(r == -1)
			printf("impossible\n");
		else
			printf("%d\n", min(r, bfs(e, s)));
	}
	return 0;
}
