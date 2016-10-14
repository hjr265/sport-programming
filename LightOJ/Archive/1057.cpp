// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1057
// Collecting Gold
// dp
// 
// 
// AC (2011-12-12 22:37:48)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

struct Loc {
	int x, y;
};

Loc g[16];
int d[16][16];

int q[1<<16][16];

int dp(int n, int x, int l) {
	if(x == (1<<n)-1)
		return d[0][l];
	int &r = q[x][l];
	if(r == -1) {
		r = 1<<28;
		for(int i = 1; i < n; ++i) if((x&(1<<i)) == 0)
			r = min(r, dp(n, x|(1<<i), i)+d[i][l]);
	}
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int m, n;
		scanf("%d %d", &m, &n);
		int k = 1;
		for(int i = 0; i < m; ++i) {
			char s[22];
			scanf("%s", s);
			for(int j = 0; j < n; ++j) {
				if(s[j] == 'g')
					g[k].x = j, g[k++].y = i;
				else if(s[j] == 'x')
					g[0].x = j, g[0].y = i;
			}
		}
		for(int i = 0; i < k; ++i) {
			for(int j = 0; j < k; ++j) if(i != j)
				d[i][j] = max(abs(g[i].x-g[j].x), abs(g[i].y-g[j].y));
		}
		SET(q);
		printf("Case %d: %d\n", no++, dp(k, 1, 0));
	}
	return 0;
}
