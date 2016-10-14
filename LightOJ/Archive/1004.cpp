// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1004
// Monkey Banana Problem
// dp
// 
// 
// AC (2011-07-31 10:21:24)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

typedef long long vlong;

int G[2010][1005];
vlong mo[2010][1005];

vlong dp(int i, int j) {
	if(i < 1 || j < 1)
		return 0;
	vlong &m = mo[i][j];
	if(m == -1)
		m = G[i][j]+max(dp(i-1, j), dp(i-1, j-1));
	return m;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		for(int i = 1; i <= N; ++i) {
			for(int j = 1; j <= i; ++j)
				scanf("%d", &G[i][j]);
		}
		for(int i = N+1; i <= 2*N-1; ++i) {
			for(int j = 1, k = i-N+1; j <= 2*N-i; ++j, ++k)
				scanf("%d", &G[i][k]);
		}
		SET(mo);
		printf("Case %d: %lld\n", no++, dp(2*N-1, N));
	}
	return 0;
}
