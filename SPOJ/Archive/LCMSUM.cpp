// In the name of Allah, Most Gracious, Most Merciful

// SPOJ/LCMSUM
// LCM Sum
// number theory
// 
// 
// AC (2012-11-25 19:26:48)

#include <cstdio>

typedef long long vlong;

vlong S[1000005], R[1000005];

void ssieve() {
	for(vlong i = 0; i < 1000005; ++i)
		S[i] = i;
	for(vlong i = 2; i < 1000005; ++i) if(S[i] == i) {
		for(vlong j = i; j < 1000005; j += i) {
			S[j] = (S[j]/i)*(i-1);
		}
	}
	for(vlong i = 1; i < 1000005; ++i) {
		for(vlong j = i; j < 1000005; j += i)
			R[j] += i*S[i];
	}
}

int main() {
	ssieve();
	int T;
	scanf("%d", &T);
	while(T--) {
		vlong n;
		scanf("%lld", &n);
		printf("%lld\n", (R[n]+1)*n/2);
	}
	return 0;
}
