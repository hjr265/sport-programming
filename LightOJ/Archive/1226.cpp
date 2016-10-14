// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1226
// One Unit Machine
// *combinatorics, dp
// 
// 
// AC (2012-01-29 22:38:02)

#include <cstdio>

typedef long long vlong;

const vlong mod = 1000000007LL;

vlong F[2000002];
vlong I[2000002];

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
	return (modpow(b, m-2, m)%m+m)%m;
}

void init() {
	F[0] = 1;
	I[0] = modinv(1, mod);
	for(vlong i = 1; i < 2000002; ++i) {
		F[i] = (F[i-1]*i)%mod;
		I[i] = (I[i-1]*modinv(i, mod))%mod;
	}
}

vlong choose(int n, int k) {
	return ((((F[n]*I[k])%mod)*I[n-k])%mod+mod)%mod;
}

int main() {
	init();
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d\n", &n);
		vlong r = 1, t;
		scanf("%lld", &t);
		for(int i = 1; i < n; ++i) {
			vlong x;
			scanf("%lld", &x);
			r = (r*choose(x-1+t+1-1, t))%mod;
			t += x;
		}
		printf("Case %d: %lld\n", no++, r);
	}
	return 0;
}
