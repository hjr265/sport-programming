// In the name of Allah, Most Gracious, Most Merciful

// UVA/11481
// Arrange the Numbers
// dp, *counting
// 
// 
// AC (2012-06-16 16:16:39)

#include <cstdio>

typedef long long vlong;

const vlong mod = 1000000007LL;

vlong f[1005];
vlong c[1005][1005];

void init() {
	f[0] = 1;
	for(int i = 1; i < 1005; ++i)
		f[i] = (f[i-1]*i)%mod;
	for(int i = 0; i < 1005; ++i)
		c[i][0] = c[i][i] = 1;
	for(int i = 1; i < 1005; ++i)
		for(int j = 1; j < i; ++j)
			c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
}

vlong ans(int N, int M, int K) {
	vlong r = 0;
	for(int i = 0; i <= M-K; ++i) {
		if(i%2 == 0)
			r += c[M-K][i]*f[N-K-i];
		else
			r -= c[M-K][i]*f[N-K-i];
		r %= mod;
    }
    return (((r*c[M][K])%mod)+mod)%mod;
}

int main() {
	init();
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N, M, K;
		scanf("%d %d %d", &N, &M, &K);
		printf("Case %d: %lld\n", no++, ans(N, M, K));
	}
	return 0;
}
