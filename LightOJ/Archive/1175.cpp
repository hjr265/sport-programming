// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1175
// Jane and the Frost Giants
// dfs and similar
// 
// 
// AC (2011-12-08 01:36:16)

#include <cstdio>
#include <cstring>
#include <map>
#include <queue>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

const int inf = 1234567890;

char g[205][205];
int f[205][205];
bool m[205][205];

void bfs1(int R, int C) {
	CLR(m);
	queue<pair<int, int> > q;
	for(int r = 0; r < R; ++r) {
		for(int c = 0; c < C; ++c) {
			f[r][c] = inf;
			if(g[r][c] == 'F') {
				pair<int, int> s(r, c);
				m[s.first][s.second] = true;
				f[s.first][s.second] = 0;
				q.push(s);
			}
		}
	}
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
			if(v.first >= 0 && v.first < R && v.second >= 0 && v.second < C && g[v.first][v.second] == '.' && !m[v.first][v.second] && (f[v.first][v.second] == -1 || f[v.first][v.second] > f[u.first][u.second] + 1)) {
				f[v.first][v.second] = f[u.first][u.second]+1;
				m[v.first][v.second] = true;
				q.push(v);
			}
		}
	}
}

int d[205][205];

int bfs2(int R, int C, const pair<int, int> &s) {
	CLR(m);
	CLR(d);
	queue<pair<int, int> > q;
	m[s.first][s.second] = true;
	d[s.first][s.second] = 0;
	q.push(s);
	while(!q.empty()) {
		pair<int, int> u = q.front();
		if(d[u.first][u.second] > 200)
			return -1;
		q.pop();
		const int x[][2] = {
			{0, -1},
			{0, 1},
			{-1, 0},
			{1, 0}
		};
		for(int i = 0; i < 4; ++i) {
			pair<int, int> v(u.first + x[i][0], u.second + x[i][1]);
			if(v.first >= 0 && v.first < R && v.second >= 0 && v.second < C && g[v.first][v.second] == '.' && !m[v.first][v.second] && f[v.first][v.second] > d[u.first][u.second] + 1) {
				d[v.first][v.second] = d[u.first][u.second] + 1;
				if(v.first == 0 || v.first == R - 1 || v.second == 0 || v.second == C - 1)
					return d[v.first][v.second] + 1;
				m[v.first][v.second] = true;
				q.push(v);
			}
		}
	}
	return -1;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int R, C;
		scanf("%d %d", &R, &C);
		for(int r = 0; r < R; ++r)
			scanf("%s", g[r]);
		SET(f);
		bfs1(R, C);
		int z = -2;
		for(int r = 0; r < R && z == -2; ++r) {
			for(int c = 0; c < C && z == -2; ++c) if(g[r][c] == 'J')
				z = bfs2(R, C, pair<int, int>(r, c));
		}
		printf("Case %d: ", no++);
		if(z != -1)
			printf("%d\n", z);
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
