// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1066
// Gathering Food
// dfs and similar
// 
// 
// AC (2011-09-14 19:25:15)

#include <cstdio>
#include <cstring>
#include <map>
#include <queue>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

char g[15][15];

int bfs(int N, pair<int, int> s, int k) {
	map<pair<int, int>, int> d;
	map<pair<int, int>, bool> m;
	queue<pair<int, int> > q;
	d[s] = 0;
	m[s] = true;
	q.push(s);
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
			if(v.first >= 0 && v.first < N && v.second >= 0 && v.second < N && g[v.first][v.second] != '#' && m[v] == false) {
				if(g[v.first][v.second] >= 'A' && g[v.first][v.second] <= 'Z' && g[v.first][v.second] > k)
					continue;
				d[v] = d[u] + 1;
				if(g[v.first][v.second] == k)
					return d[v];
				m[v] = true;
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
		int N;
		scanf("%d\n", &N);
		SET(g);
		for(int r = 0; r < N; ++r)
			gets(g[r]);
		struct {
			int r, c;
		} F[28];
		SET(F);
		for(int r = 0; r < N; ++r) {
			for(int c = 0; c < N; ++c) if(g[r][c] >= 'A' && g[r][c] <= 'Z')
				F[g[r][c] - 'A'].r = r, F[g[r][c] - 'A'].c = c;
		}
		int z = 0;
		for(int i = 1; F[i].r != -1; ++i) {
			int r = bfs(N, pair<int, int>(F[i - 1].r, F[i - 1].c), 'A' + i);
			if(r == -1) {
				z = -1;
				break;
			}
			z += r;
		}
		printf("Case %d: ", no++);
		if(z == -1)
			printf("Impossible\n");
		else
			printf("%d\n", z);
	}
	return 0;
}
