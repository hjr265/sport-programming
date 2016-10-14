// In the name of Allah, Most Gracious, Most Merciful

// UVA/10721
// Bar Codes
// dp
// 
// 
// AC (2012-06-12 10:37:00)

#include <cstdio>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))

typedef long long vlong;

int n, k, m;
vlong D[50+2][50+2][50+2];

vlong dp(int n, int k, int m) {
	if(n == 0 && k == 0)
		return 1;
	if(n < 0 || k < 0)
		return 0;
	vlong &r = D[n][k][m];
	if(r == -1) {
		r = 0;
		for(int i = 1; i <= m; ++i)
			r += dp(n-i, k-1, m);
	}
	return r;
}

int main() {
	SET(D);
	while(scanf("%d %d %d", &n, &k, &m) == 3)
		printf("%lld\n", dp(n, k, m));
	return 0;
}
