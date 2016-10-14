// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1012
// Guilty Prince
// dfs and similar
// 
// 
// AC (2011-07-31 11:46:53)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

char G[25][25];
char v[25][25];

int dfs(int W, int H, int i, int j) {
	v[i][j] = 1;
	int c = 1;
	const int dx[][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	for(int k = 0; k < 4; ++k) {
		int y = i + dx[k][0], x = j + dx[k][1];
		if(x >= 0 && x < W && y >= 0 && y < H && G[y][x] == '.' && v[y][x] == 0)
			c += dfs(W, H, y, x);
	}
	return c;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int W, H;
		scanf("%d %d", &W, &H);
		int x, y;
		for(int i = 0; i < H; ++i) {
			scanf("%s", &G[i]);
			for(int j = 0; j < W; ++j) if(G[i][j] == '@')
				y = i, x = j;
		}
		CLR(v);
		printf("Case %d: %d\n", no++, dfs(W, H, y, x));
		
	}
	return 0;
}
