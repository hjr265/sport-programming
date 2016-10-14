// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1145
// Dice (I)
// dp
// 
// 
// AC (2012-05-01 16:27:54)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

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
			for(int j = 1002; j <= S+1002; ++j)
				D[i%2][j] = (D[i%2][j-1]-D[(i+1)%2][j-K-1]+D[(i+1)%2][j-1])%mod;
		}
		printf("Case %d: %lld\n", no++, (D[(N+1)%2][S+1002]+mod)%mod);
	}
	return 0;
}
