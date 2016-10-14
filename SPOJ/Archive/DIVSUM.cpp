// In the name of Allah, Most Gracious, Most Merciful

// SPOJ/DIVSUM
// Divisor Summation
// number theory
// 
// 
// AC (2012-11-25 06:32:51)

#include <cstdio>

int P[500005];

void ssieve() {
	for(int i = 0; i < 500000; ++i)
		P[i] = 1;
	for(int i = 2; i < 500000; ++i) if(P[i] == 1) {
		for(int j = i; j < 500000; j += i) {
			int k = 1, x = j;
			while(x%i == 0)
				k *= i, x /= i;
			P[j] *= (k*i-1)/(i-1);
		}
	}
}

int main() {
	ssieve();
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", P[n]-n);
	}
	return 0;
}
