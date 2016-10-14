// In the name of Allah, Most Gracious, Most Merciful

// SPOJ/PERIOD
// Period
// strings
// 
// 
// AC (2012-07-15 16:52:16)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define SET(c, v) memset(c, v, sizeof(c))

using namespace std;

char  S[1000005];
int P[1000005], Z[1000005];

void solve() {
	strcat(S, "$");
	int n = strlen(S);
	P[0] = -1;
	P[1] = 0;
	for(int i = 2, j = 0; i < n; ) {
		if(S[i-1] == S[j])
			P[i++] = ++j;
		else if(j > 0)
			j = P[j];
		else
			P[i++] = 0;
	}
	--n;
	SET(Z, -1);
	for(int i = 1; i <= n; ++i) if(Z[i] == -1) {
		for(int j = 2; i*j <= n; ++j) if(P[i*j] == i*(j-1))
			Z[i*j] = Z[i*(j-1)]+1;
	}
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		scanf("%s", S);
		solve();
		printf("Test case #%d\n", no++);
		for(int i = 1; i <= N; ++i) if(Z[i] >= 0)
			printf("%d %d\n", i, Z[i]+2);
		printf("\n");
	}
	return 0;
}
