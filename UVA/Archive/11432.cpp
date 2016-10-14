// In the name of Allah, Most Gracious, Most Merciful

// UVA/11432
// Busy Programmer
// dp
// 
// 
// AC (2012-06-15 12:13:06)

#include <cstdio>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))

typedef long long vlong;

int D, G;
vlong M[33+2][33+2][33+2][2][2];
vlong Z[33+2][33+2];

vlong dp(int i, int j, int k, int l, int m) {
	if(i > D || j > D || k > G || i == D && j != D && m == 1 || i != D && j == D && m == 0)
		return 0;
	if(i == D || j == D)
		return 1;
	vlong &r = M[i][j][k][l][m];
	if(r == -1) {
		r = 0;
		switch(l) {
		case 0:
			r += dp(i+1, j, k+1, 0, m);
			if(k > 0)
				r += dp(i, j, 0, 1, m);
			break;
		case 1:
			r += dp(i, j+1, k+1, 1, m);
			if(k > 0)
				r += dp(i, j, 0, 0, m);
			break;
		}
	}
	return r;
}

int main() {
	SET(Z);
	int no = 1;
	while(scanf("%d %d", &D, &G) == 2 && (D != -1 || G != -1)) {
		vlong &r = Z[D][G];
		if(r == -1) {
			SET(M);
			r = dp(0, 0, 0, 0, 0)+dp(0, 0, 0, 1, 1);
		}
		printf("Case %d: %lld\n", no++, r);
	}
	return 0;
}
