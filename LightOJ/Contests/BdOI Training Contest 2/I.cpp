// In the name of Allah, Most Gracious, Most Merciful

// Digit Count
// dp
// AC (306)

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))

int G[15];
int M[15][15];

int dp(int m, int n, int x) {
	if(n == 0)
		return 1;
	int &r = M[n][x];
	if(r == -1) {
		r = 0;
		for(int i = 0; i < m; ++i) if(abs(G[i]-x) <= 2)
			r += dp(m, n-1, G[i]);
	}
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T-- > 0) {
		int m, n;
		scanf("%d %d", &m, &n);
		for(int i = 0; i < m; ++i)
			scanf("%d", &G[i]);
		SET(M);
		int r = 0;
		for(int i = 0; i < m; ++i)
			r += dp(m, n-1, G[i]);
		printf("Case %d: %d\n", no++, r);
	}
	return 0;
}
