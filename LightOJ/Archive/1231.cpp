// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1231
// Coin Change (I)
// dp
// 
// 
// AC (2011-11-22 10:44:04)

#include <cstdio>
#include <cstring>

typedef long long vlong;

vlong S[10005];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, K;
		scanf("%d %d", &n, &K);
		int A[n], C[n];
		for(int i = 0; i < n; ++i)
			scanf("%d", &A[i]);
		for(int i = 0; i < n; ++i)
			scanf("%d", &C[i]);
		memset(S, 0, sizeof(S));
		S[0] = 1;
		for(int i = 0; i < n; ++i) {
			for(int j = K; j >= 0; --j) if(S[j] > 0) {
				for(int l = 1; l <= C[i]; ++l)
					S[j+A[i]*l] = (S[j+A[i]*l]+S[j])%100000007;
			}
		}
		printf("Case %d: %d\n", no++, S[K]);
	}
	return 0;
}
