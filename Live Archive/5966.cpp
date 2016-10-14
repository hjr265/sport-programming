// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/5966
// Blade and Sword
// dfs and similar
// 
// 
// AC (2012-09-11 11:43:22)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

#define SET(c, v) memset(c, v, sizeof(c))

using namespace std;

int m, n;
char G[202][202];
int C[202][202];
pair<int, int> P;
pair<int, int> D;
vector<pair<int, int> > L;


int bfs(pair<int, int> s, pair<int, int> t) {
	SET(C, -1);
	queue<pair<int, int> > q;
	C[s.first][s.second] = 0;
	q.push(s);
	while(!q.empty()) {
		pair<int, int> u = q.front();
		q.pop();
		
		const int x[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		for(int i = 0; i < 4; ++i) {
			pair<int, int> v(u.first+x[i][0], u.second+x[i][1]);
			if(G[v.first][v.second] != '#' && C[v.first][v.second] == -1) {
				if(v == t)
					return C[u.first][u.second]+1;
					
				if(G[v.first][v.second] == '*') {
					for(int j = 0; j < L.size(); ++j) if(L[j] != v) {
						C[L[j].first][L[j].second] = C[u.first][u.second]+2;
						q.push(L[j]);
					}
					
					C[v.first][v.second] = C[u.first][u.second]+3;
					q.push(v);
				} else {
					C[v.first][v.second] = C[u.first][u.second]+1;
					q.push(v);
				}
			}
		}
	}
	return 1<<28;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &m, &n);
		for(int i = 0; i < m; ++i)
			scanf("%s", G[i]);
		
		L.clear();
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) switch(G[i][j]) {
			case 'P':
				P = pair<int, int>(i, j);
				G[i][j] = '.';
				break;
			case 'D':
				D = pair<int, int>(i, j);
				G[i][j] = '.';
				break;
			case '*':
				L.push_back(pair<int, int>(i, j));
				break;
			}
		}
		if(L.size() == 1) {
			G[L[0].first][L[0].second] = '#';
			L.clear();
		}
		
		printf("Case %d: ", no++);
		int r = min(bfs(P, D), bfs(D, P));
		if(r == 1<<28)
			printf("impossible\n");
		else
			printf("%d\n", r);
	}
	return 0;
}
