// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1021
// Painful Bases
// dp
// 
// 
// AC (2012-02-03 18:32:21)

#include <cstdio>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))

typedef long long vlong;

int d[18];
vlong m[(1<<16)+2][22];

vlong dp(int N, int base, int K, int x, int v) {
	if(x == (1<<N)-1)
		return v == 0;
	vlong &r = m[x][v];
	if(r == -1) {
		r = 0;
		for(int i = 0; i < N; ++i) if((x&(1<<i)) == 0) {
			r += dp(N, base, K, x|(1<<i), (v*base+d[i])%K);
		}
	}
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int base, K;
		scanf("%d %d", &base, &K);
		char s[18];
		scanf("%s", s);
		for(int i = 0; s[i]; ++i)
			d[i] = s[i] >= 'A' && s[i] <= 'Z' ? s[i]-'A'+10 : s[i]-'0';
		SET(m);
		printf("Case %d: %lld\n", no++, dp(strlen(s), base, K, 0, 0));
	}
	return 0;
}
