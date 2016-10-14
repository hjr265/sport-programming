// In the name of Allah, Most Gracious, Most Merciful

// Coin Change (II)
// dp
// AC (133)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

typedef long long vlong;

vlong S[100000+2];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, K;
		scanf("%d %d", &n, &K);
		int A[n], C[n];
		for(int i = 0; i < n; ++i)
			scanf("%d", &A[i]);
		CLR(S);
		S[0] = 1;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j <= K; ++j) if(S[j] > 0)
				S[j+A[i]] = (S[j+A[i]]+S[j])%100000007;
		printf("Case %d: %lld\n", no++, S[K]);
	}
	return 0;
}
