// In the name of Allah, Most Gracious, Most Merciful

// UVA/10616
// Divisible Group Sums
// dp
// 
// 
// AC (2012-06-16 08:34:52)

#include <cstdio>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))

typedef long long vlong;

int N, Q;
int R[200+2];
int D, M;
vlong Z[200+2][10+2][20+2];

vlong dp(int i, int j, int k) {
	if(j > M)
		return 0;
	if(j == M && k == 0)
		return 1;
	if(i >= N)
		return 0;
	vlong &r = Z[i][j][k];
	if(r == -1)
		r = dp(i+1, j+1, ((k%D+R[i])%D+D)%D)+dp(i+1, j, k);
	return r;
}

int main() {
	int no = 1;
	while(scanf("%d %d", &N, &Q) == 2 && (N != 0 || Q != 0)) {
		for(int i = 0; i < N; ++i)
			scanf("%d", &R[i]);
		printf("SET %d:\n", no++);
		for(int i = 1; i <= Q; ++i) {
			scanf("%d %d", &D, &M);
			SET(Z);
			printf("QUERY %d: %lld\n", i, dp(0, 0, 0));
		}
	}
	return 0;
}
