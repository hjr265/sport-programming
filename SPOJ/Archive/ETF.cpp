// In the name of Allah, Most Gracious, Most Merciful

// SPOJ/ETF
// Euler Totient Function
// number theory
// 
// 
// AC (2012-11-25 06:25:37)

#include <cstdio>

int P[1000005];

void tsieve() {
	for(int i = 0; i < 1000005; ++i)
		P[i] = i;
	for(int i = 2; i < 1000005; ++i) if(P[i] == i) {
		for(int j = i; j < 1000005; j += i)
			P[j] = (P[j]/i)*(i-1);
	}
}

int main() {
	tsieve();
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", P[n]);
	}
	return 0;
}
