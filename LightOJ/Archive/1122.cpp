// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1122
// Digit Count
// dp
// 
// 
// AC (2011-07-31 11:06:43)

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))

int G[15];
int mo[15][15];

int dp(int m, int n, int x) {
	if(n == 0)
		return 1;
	int &z = mo[n][x];
	if(z == -1) {
		z = 0;
		for(int i = 0; i < m; ++i) if(abs(G[i]-x) <= 2)
			z += dp(m, n-1, G[i]);
	}
	return z;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int m, n;
		scanf("%d %d", &m, &n);
		for(int i = 0; i < m; ++i)
			scanf("%d", &G[i]);
		SET(mo);
		int z = 0;
		for(int i = 0; i < m; ++i)
			z += dp(m, n-1, G[i]);
		printf("Case %d: %d\n", no++, z);
	}
	return 0;
}
