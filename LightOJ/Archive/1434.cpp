// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1434
// Patch Quilt
// dfs and similar
// 
// 
// AC (2012-05-27 22:15:42)

#include <cstdio>
#include <cstring>
#include <utility>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

const char D[][5] = {
	"UL",
	"U",
	"UR",
	"L",
	"*",
	"R",
	"DL",
	"D",
	"DR"
};

int R, C;
char G[32][32];
char K[18];
bool M[32][32][18];
char P[18];

bool dfs(pair<int, int> u, int i) {
	if(K[i] == '\0')
		return true;
	if(u.first < 0 || u.first >= R || u.second < 0 || u.second >= C)
		return false;
	if(G[u.first][u.second] != K[i])
		return false;
	if(M[u.first][u.second][i])
		return false;
	M[u.first][u.second][i] = true;
	const int x[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
	for(int l = 0; l < 9; ++l) {
		pair<int, int> v(u.first+x[l][0], u.second+x[l][1]);
		if(dfs(v, i+1)) {
			P[i] = l;
			return true;
		}
	}
	return false;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &R, &C);
		for(int i = 0; i < R; ++i)
			scanf("%s", G[i]);
		int N;
		scanf("%d", &N);
		printf("Case %d:\n", no++);
		while(N--) {
			scanf("%s", K);
			printf("%s ", K);
			bool f = false;
			for(int i = 0; i < R && !f; ++i) {
				for(int j = 0; j < C; ++j) if(G[i][j] == K[0]) {
					CLR(M);
					if(dfs(pair<int, int>(i, j), 0)) {
						printf("found: (%d,%d)", i+1, j+1);
						for(int l = 1; K[l]; ++l)
							printf(", %s", D[P[l-1]]);
						f = true;
						break;
					}
				}
			}
			if(!f)
				printf("not found");
			printf("\n");
		}
	}
	return 0;
}
