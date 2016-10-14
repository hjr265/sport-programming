// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1368
// Truchet Tiling
// dfs and similar
// 
// 
// AC (2012-05-11 15:14:41)

#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

const double pi = acos(-1.0);

int R, C;
char G[102][102];
bool V[202][202];
bool W[202][202];
double Z[202][202];

void bfs(pair<int, int> s) {
	CLR(V);
	queue<pair<int, int> > q1;
	V[s.first][s.second] = true;
	q1.push(s);
	double r = 0;
	while(!q1.empty()) {
		pair<int, int> u = q1.front();
		q1.pop();
		if(u.first < 0 || u.first >= 2*R || u.second < 0 || u.second >= 2*C)
			continue;
		switch(G[u.first/2][u.second/2]) {
		case '0':
			switch(((u.first%2)<<1)+(u.second%2)) {
			case 0:
				r += (pi*1*1)/4;
				if(!V[u.first-1][u.second]) {
					V[u.first-1][u.second] = true;
					q1.push(pair<int, int>(u.first-1, u.second));
				}
				if(!V[u.first][u.second-1]) {
					V[u.first][u.second-1] = true;
					q1.push(pair<int, int>(u.first, u.second-1));
				}
				break;
			case 1:
				r += 1*1+(1*1-((pi*1*1)/4));
				if(!V[u.first-1][u.second]) {
					V[u.first-1][u.second] = true;
					q1.push(pair<int, int>(u.first-1, u.second));
				}
				if(!V[u.first][u.second+1]) {
					V[u.first][u.second+1] = true;
					q1.push(pair<int, int>(u.first, u.second+1));
				}
				if(!V[u.first+1][u.second-1]) {
					V[u.first+1][u.second-1] = true;
					q1.push(pair<int, int>(u.first+1, u.second-1));
				}
				break;
			case 2:
				r += 1*1+(1*1-((pi*1*1)/4));
				if(!V[u.first][u.second-1]) {
					V[u.first][u.second-1] = true;
					q1.push(pair<int, int>(u.first, u.second-1));
				}
				if(!V[u.first+1][u.second]) {
					V[u.first+1][u.second] = true;
					q1.push(pair<int, int>(u.first+1, u.second));
				}
				if(!V[u.first-1][u.second+1]) {
					V[u.first-1][u.second+1] = true;
					q1.push(pair<int, int>(u.first-1, u.second+1));
				}
				break;
			case 3:
				r += (pi*1*1)/4;
				if(!V[u.first+1][u.second]) {
					V[u.first+1][u.second] = true;
					q1.push(pair<int, int>(u.first+1, u.second));
				}
				if(!V[u.first][u.second+1]) {
					V[u.first][u.second+1] = true;
					q1.push(pair<int, int>(u.first, u.second+1));
				}
				break;
			}
			break;
		case '1':
			switch(((u.first%2)<<1)+(u.second%2)) {
			case 0:
				r += 1*1+(1*1-((pi*1*1)/4));
				if(!V[u.first][u.second-1]) {
					V[u.first][u.second-1] = true;
					q1.push(pair<int, int>(u.first, u.second-1));
				}
				if(!V[u.first-1][u.second]) {
					V[u.first-1][u.second] = true;
					q1.push(pair<int, int>(u.first-1, u.second));
				}
				if(!V[u.first+1][u.second+1]) {
					V[u.first+1][u.second+1] = true;
					q1.push(pair<int, int>(u.first+1, u.second+1));
				}
				break;
			case 1:
				r += (pi*1*1)/4;
				if(!V[u.first-1][u.second]) {
					V[u.first-1][u.second] = true;
					q1.push(pair<int, int>(u.first-1, u.second));
				}
				if(!V[u.first][u.second+1]) {
					V[u.first][u.second+1] = true;
					q1.push(pair<int, int>(u.first, u.second+1));
				}
				break;
			case 2:
				r += (pi*1*1)/4;
				if(!V[u.first+1][u.second]) {
					V[u.first+1][u.second] = true;
					q1.push(pair<int, int>(u.first+1, u.second));
				}
				if(!V[u.first][u.second-1]) {
					V[u.first][u.second-1] = true;
					q1.push(pair<int, int>(u.first, u.second-1));
				}
				break;
			case 3:
				r += 1*1+(1*1-((pi*1*1)/4));
				if(!V[u.first][u.second+1]) {
					V[u.first][u.second+1] = true;
					q1.push(pair<int, int>(u.first, u.second+1));
				}
				if(!V[u.first+1][u.second]) {
					V[u.first+1][u.second] = true;
					q1.push(pair<int, int>(u.first+1, u.second));
				}
				if(!V[u.first-1][u.second-1]) {
					V[u.first-1][u.second-1] = true;
					q1.push(pair<int, int>(u.first-1, u.second-1));
				}
				break;
			}
			break;
		}
	}
	for(int i = 0; i < 2*R; ++i) {
		for(int j = 0; j < 2*C; ++j) if(V[i][j]) {
			W[i][j] = true;
			Z[i][j] = r;
		}
	}
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &R, &C);
		for(int i = 0; i < R; ++i)
			scanf("%s", G[i]);
		int Q;
		scanf("%d", &Q);
		CLR(W);
		printf("Case %d:\n", no++);
		while(Q--) {
			int x, y;
			scanf("%d %d", &x, &y);
			switch(((x%2)<<1)+(y%2)) {
			case 0:
				if(!W[max(x-1, 0)][max(y-1, 0)])
					bfs(pair<int, int>(max(x-1, 0), max(y-1, 0)));
				printf("%0.8lf\n", Z[max(x-1, 0)][max(y-1, 0)]);
				break;
			case 3:
				switch(G[x/2][y/2]) {
				case '0':
					if(!W[max(x-1, 0)][y])
						bfs(pair<int, int>(max(x-1, 0), y));
					printf("%0.8lf\n", Z[max(x-1, 0)][y]);
					break;
				case '1':
					if(!W[max(x-1, 0)][max(y-1, 0)])
						bfs(pair<int, int>(max(x-1, 0), max(y-1, 0)));
					printf("%0.8lf\n", Z[max(x-1, 0)][max(y-1, 0)]);
					break;
				}
				break;
			default:
				printf("0\n");
				break;
			}
		}
	}
	return 0;
}
