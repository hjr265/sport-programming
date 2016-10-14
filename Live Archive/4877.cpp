// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/4877
// Non-Decreasing Digits
// combinatorics
// 
// 
// AC (2011-07-30 08:05:11)

#include <cstdio>

typedef long long vlong;

int main() {
	vlong C[75] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
	for(int i = 10; i < 75; ++i)
		C[i] = C[i-1]*i/(i-9);
	int P;
	scanf("%d", &P);
	while(P--) {
		int t, N;
		scanf("%d %d", &t, &N);
		printf("%d %lld\n", t, C[N+9]/C[9]);
	}
	return 0;
}
