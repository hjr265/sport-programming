// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1054
// Efficient Pseudo Code
// number theory
// 
// 
// AC (2012-01-05 16:50:44)

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef long long uvlong;

const uvlong mod = 1000000007ULL;

bool s[80000];
vector<uvlong> p;

void init() {
	memset(s, 0, sizeof(s));
	p.push_back(2);
	for(uvlong i = 3; i < 80000; i += 2) if(!s[i]) {
		p.push_back(i);
		for(uvlong j = i*i; j < 80000; j += 2*i)
			s[j] = true;
	}
}

uvlong modpow(uvlong b, uvlong p, uvlong m) {
	uvlong r = 1;
	for(; p; p /= 2) {
		b %= m;
		if(p&1)
			r = (r*b)%m;
		b *= b;
	}
	return r;
}

uvlong modinv(uvlong b, uvlong m) {
	return (modpow(b, m-2, m)+m)%m;
}

uvlong ans(uvlong n, uvlong m) {
	uvlong r = 1;
	for(int i = 0, l = p.size(); i < l && n > 1; ++i) if(n%p[i] == 0) {
		uvlong k = 0;
		while(n%p[i] == 0)
			++k, n /= p[i];
		r = (((r*(modpow(p[i], k*m+1, mod)-1))%mod)*modinv(p[i]-1, mod))%mod;
	}
	if(n > 1)
		r = (((r*(modpow(n, m+1, mod)-1))%mod)*modinv(n-1, mod))%mod;
	return (r+mod)%mod;
}

int main() {
	init();
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		uvlong n, m;
		scanf("%llu %llu", &n, &m);
		printf("Case %d: %llu\n", no++, ans(n, m)%mod);
	}
	return 0;
}
