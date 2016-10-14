// In the name of Allah, Most Gracious, Most Merciful

// Squished Status
// dp
// AC (22:18)

#include <cstdio>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))

typedef long long vlong;

const vlong mod = 4207849484LL;

int M, L;
char S[1002];
vlong D[1002][1002];

vlong dp(int i, int j) {
	if(i >= L)
		return 1;
	if(S[i] == '0')
		return 0;
	vlong &r = D[i][j];
	if(r == -1) {
		r = 0;
		for(int x = S[i]-'0', k = i; x <= M && k < L; ++k, x *= 10, x += S[k]-'0')
			r = (r+dp(k+1, j+1))%mod;
	}
	return r;
}

int main() {
	int N, no = 1;
	scanf("%d", &N);
	while(N--) {
		scanf("%d %s", &M, S);
		L = strlen(S);
		SET(D);
		printf("Case #%d: %lld\n", no++, dp(0, 0));
	}
	return 0;
}
