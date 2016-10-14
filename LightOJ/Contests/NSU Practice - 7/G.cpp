// In the name of Allah, Most Gracious, Most Merciful

// Race
// combinatorics, dp
// AC (1174)

#include <cstdio>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))

const int mod = 10056;

int C[1002][1002];

void init() {
	for(int i = 1; i < 1002; ++i)
		C[i][1] = i%mod, C[i][i] = 1;
	for(int i = 1; i < 1002; ++i)
		for(int j = 2; j < i; ++j)
			C[i][j] = (C[i-1][j]+C[i-1][j-1])%mod;
}

int M[1002];

int dp(int n) {
	if(n == 0)
		return 1;
	if(n < 0)
		return 0;
	int &r = M[n];
	if(r == -1) {
		r = 0;
		for(int i = 1; i <= n; ++i)
			r = (r+dp(n-i)*C[n][i])%mod;
	}
	return r;
}

int main() {
	init();
	SET(M);
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		printf("Case %d: %d\n", no++, dp(n));
	}
	return 0;
}
