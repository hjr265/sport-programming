// In the name of Allah, Most Gracious, Most Merciful

// Throwing Dice
// dp
// AC (326)

#include <cstdio>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))

typedef long long vlong;

template<class T> T gcd(T a, T b) {
	return b == 0 ? a : gcd(b, a%b);
}

int n, x;
vlong p[26];
vlong mo[26][152];

vlong dp(int i, int s) {
	if(s >= x)
		return p[n-i];
	if(i == n)
		return 0;
	vlong &r = mo[i][s];
	if(r == -1) {
		r = 0;
		for(int a = 1; a <= 6; ++a)
			r += dp(i+1, s+a);
	}
	return r;
}

int main() {
	p[0] = 1;
	for(int i = 1; i < 26; ++i)
		p[i] = p[i-1]*6;
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &x);
		SET(mo);
		vlong r = dp(0, 0), g = gcd(r, p[n]);
		printf("Case %d: ", no++);
		if(g == p[n])
			printf("%lld\n", r/g);
		else
			printf("%lld/%lld\n", r/g, p[n]/g);
	}
	return 0;
}
