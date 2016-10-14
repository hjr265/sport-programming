// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1193
// Dice (II)
// dp
// 
// 
// AC (2012-05-04 14:55:24)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

typedef long long vlong;

const vlong mod = 100000007LL;

vlong D[2][15002+1002];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N, K, S;
		scanf("%d %d %d", &N, &K, &S);
		CLR(D);
		D[1][1002] = 1;
		for(int i = 0; i < N; ++i) {
			vlong x = 0, y = 0;
			for(int j = 1002; j <= S+1002; ++j) {
				x += D[(i+1)%2][j-1];
				x -= D[(i+1)%2][j-K-1];
				y -= D[(i+1)%2][j-K-1]*K;
				y += x;
				D[i%2][j] = y%mod;
			}
		}
		printf("Case %d: %lld\n", no++, (D[(N+1)%2][S+1002]+mod)%mod);
	}
	return 0;
}
