// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1159
// Batman
// dp
// 
// 
// AC (2011-07-31 11:29:08)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

char P[55];
char Q[55];
char R[55];

int mo[55][55][55];

int dp(int i, int j, int k) {
	if(i < 0 || j < 0 || k < 0)
		return 0;
	int &m = mo[i][j][k];
	if(m == -1) {
		if(P[i] == Q[j] && P[i] == R[k]) {
			m = dp(i-1, j-1, k-1)+1;
		} else {
			m = max(dp(i-1, j, k), dp(i, j-1, k));
			m = max(dp(i, j, k-1), m);
		}
	}
	return m;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", &P);
		scanf("%s", &Q);
		scanf("%s", &R);
		SET(mo);
		printf("Case %d: %d\n", no++, dp(strlen(P), strlen(Q), strlen(R))-1);
	}
	return 0;
}
