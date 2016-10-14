// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1422
// Halloween Costumes
// dp
// 
// 
// AC (2012-03-12 01:38:49)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

int A[102];
int d[102][102];

int dp(int i, int j) {
	if(i >= j)
		return 0;
	int &r = d[i][j];
	if(r == -1) {
		r = dp(i+1, j)+1;
		for(int k = i+1; k < j; ++k) if(A[i] == A[k])
			r = min(r, dp(i+1, k)+dp(k, j));
	}
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
			scanf("%d", &A[i]);
		SET(d);
		printf("Case %d: %d\n", no++, dp(0, N));
	}
	return 0;
}
