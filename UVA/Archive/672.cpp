// In the name of Allah, Most Gracious, Most Merciful

// UVA/672
// Gangsters
// dp
// 
// 
// AC (2012-06-14 13:47:28)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

int N, K, T;
int T2[100+2], P[100+2], S[100+2];

int D[30000+5][100+2];
int X[30000+5][100+2];

int dp(int i, int j) {
	if(i > T)
		return 0;
	int &r = D[i][j];
	if(r == -1) {
		if(j < K)
			r = max(r, dp(i+1, j+1)+X[i][j]);
		r = max(r, dp(i+1, j)+X[i][j]);
		if(j > 0)
			r = max(r, dp(i+1, j-1)+X[i][j]);
	}
	return r;
}

int main() {
	int M;
	scanf("%d", &M);
	while(M--) {
		scanf("%d %d %d", &N, &K, &T);
		for(int i = 0; i < N; ++i)
			scanf("%d", &T2[i]);
		for(int i = 0; i < N; ++i)
			scanf("%d", &P[i]);
		for(int i = 0; i < N; ++i)
			scanf("%d", &S[i]);
		CLR(X);
		for(int i = 0; i < N; ++i)
			X[T2[i]][S[i]] += P[i];
		SET(D);
		printf("%d\n", dp(0, 0));
		if(M > 0)
			printf("\n");
	}
	return 0;
}
