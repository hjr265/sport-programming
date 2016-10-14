// In the name of Allah, Most Gracious, Most Merciful

// SPOJ/FCTRL
// Factorial
// number theory
// 
// 
// AC (2012-11-24 19:37:11)

#include <cstdio>

typedef long long vlong;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		vlong Z = 0;
		while(N)
			N /= 5, Z += N;
		printf("%lld\n", Z);
	}
	return 0;
}
