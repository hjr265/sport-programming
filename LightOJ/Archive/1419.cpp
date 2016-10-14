// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1419
// Necklace
// combinatorics
// 
// 
// AC (2012-02-28 00:07:49)

#include <cstdio>

typedef long long vlong;

const vlong mod = 1000000007LL;

int t[1002];

void tsieve() {
	for(int i = 1; i < 1002; ++i)
		t[i] = i;
	for(int i = 2; i < 1002; ++i) if(t[i] == i) {
		for(int j = i; j < 1002; j += i)
			t[j] = (t[j]/i)*(i-1);
	}
}

vlong modpow(vlong b, vlong p, vlong m) {
	vlong r = 1;
	for(; p; p >>= 1, b *= b) {
		b %= m;
		if(p&1)
			r = (r*b)%m;
	}
	return r;
}

vlong modinv(vlong b, vlong m) {
	return modpow(b, m-2, m);
}

int main() {
	tsieve();
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		vlong K;
		scanf("%d %lld", &n, &K);
		vlong r = 0;
		for(int d = 1; d <= n; ++d) if(n%d == 0)
			r = (r+t[d]*modpow(K, n/d, mod))%mod;
		r *= modinv(n, mod);
		printf("Case %d: %lld\n", no++, (r%mod+mod)%mod);
	}
	return 0;
}
