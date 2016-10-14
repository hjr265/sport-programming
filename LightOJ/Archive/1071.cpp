// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1071
// Baker Vai
// *dp, flows
// 
// 
// AC (2012-02-18 21:04:16)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

int g[102][102];
int mo[102][102][102][4];

int dp(int m, int n, int x1, int x2, int y, int v) {
	if(x1 == n-2 && x2 == n-1 && y == m-1 && v == 0)
		return 0;
	int &r = mo[y][x1][x2][v];
	if(r == -1) {
		r = 0;
		switch(v) {
		case 0:
			if(x1 < x2-1)
				r = max(r, dp(m, n, x1+1, x2, y, 0)+g[y][x1+1]);
			r = max(r, dp(m, n, x1, x2, y, 1));
			break;
		case 1:
			if(x2 < n-1)
				r = max(r, dp(m, n, x1, x2+1, y, 1)+g[y][x2+1]);
			if(x1 < x2)
				r = max(r, dp(m, n, x1, x2, y, 2));
			break;
		case 2:
			if(x1 < x2 && y < m-1)
				r = max(r, dp(m, n, x1, x2, y+1, 0)+g[y+1][x1]+g[y+1][x2]);
			break;
		}
	}
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int m, n;
		scanf("%d %d", &m, &n);
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j)
				scanf("%d", &g[i][j]);
		}
		SET(mo);
		printf("Case %d: %d\n", no++, dp(m, n, 0, 0, 0, 1)+g[0][0]);
	}
	return 0;
}
