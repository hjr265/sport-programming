// In the name of Allah, Most Gracious, Most Merciful

// Combinations
// combinatorics, number theory
// AC (82)

#include <cstdio>

typedef long long vlong;

const int mod = 1000003;

vlong F[1000002];
vlong I[1000002];

vlong modpow(vlong b, vlong p, vlong m) {
	vlong r = 1;
	for(; p; p >>= 1) {
		b %= m;
		if(p&1)
			r = (r*b)%m;
		b *= b;
	}
	return r;
}

vlong modinv(vlong b, vlong m) {
	return modpow(b, m-2, m);
}

void init() {
	F[0] = 1;
	I[0] = modinv(1, mod);
	for(vlong i = 1; i < 1000002; ++i) {
		F[i] = (F[i-1]*i)%mod;
		I[i] = (I[i-1]*modinv(i, mod))%mod;
	}
}

vlong choose(int n, int k) {
	return ((F[n]*I[k]*I[n-k])%mod+mod)%mod;
}

int main() {
	init();
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, k;
		scanf("%d %d", &n, &k);
		printf("Case %d: %lld\n", no++, choose(n, k));
	}
	return 0;
}
