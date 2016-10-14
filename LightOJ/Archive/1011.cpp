// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1011
// Marriage Ceremonies
// dp
// 
// 
// AC (2011-07-31 10:51:03)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

int G[20][20];
int mo[20][1<<18];

int dp(int N, int i, int k) {
	if(i == N)
		return 0;
	int &m = mo[i][k];
	if(m == -1) {
		m = 0;
		for(int j = 1, l = 0; j < (1<<N); j <<= 1, l += 1) if((k&j) == 0)
			m = max(G[i][l]+dp(N, i+1, k|j), m);
	}
	return m;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j)
				scanf("%d", &G[i][j]);
		}
		SET(mo);
		printf("Case %d: %d\n", no++, dp(N, 0, 0));
	}
	return 0;
}
