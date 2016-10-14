// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1068
// Investigation
// dp
// 
// 
// AC (2012-03-12 01:08:35)

#include <cstdio>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))

int N[12];
int M[12][2][82][82];

int dp(int K, int i, int s, int x, int y) {
	if(i == -1 && x == 0 && y == 0)
		return 1;
	if(i == -1)
		return 0;
	int &r = M[i][s][x][y];
	if(r == -1) {
		r = 0;
		for(int t = 0; t <= (s ? 9 : N[i]); ++t)
			r += dp(K, i-1, s||t<N[i], (x*10+t)%K, (y+t)%K);
	}
	return r;
}

int count(int A, int K) {
	if(K > 82)
		return 0;
	CLR(N);
	for(int i = 0; A; ++i, A /= 10)
		N[i] = A%10;
	SET(M);
	return dp(K, 11, 0, 0, 0);
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int A, B, K;
		scanf("%d %d %d", &A, &B, &K);
		printf("Case %d: %d\n", no++, count(B, K)-count(A-1, K));
	}
	return 0;
}
