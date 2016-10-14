// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1032
// Fast Bit Calculations
// dp
// 
// 
// AC (2012-02-04 15:00:10)

#include <cstdio>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))

typedef long long vlong;

vlong m[35][2][2];

vlong dp(vlong N, int i, int p, int s) {
	if(i < 0)
		return 0;
	vlong &r = m[i][p][s];
	if(r == -1) {
		if((1LL<<i) > N) {
			r = dp(N, i-1, 0, 0);
		} else {
			if(s) {
				r = dp(N, i-1, 0, 1)+dp(N, i-1, 1, 1)+p*(1<<i);
			} else {
				if((N&(1LL<<i)) == 0)
					r = dp(N, i-1, 0, 0);
				else
					r = dp(N, i-1, 0, 1)+dp(N, i-1, 1, 0)+p*((N&((1<<i)-1))+1);
			}
		}
		
	}
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong N;
		scanf("%lld", &N);
		SET(m);
		printf("Case %d: %lld\n", no++, dp(N, 33, 0, 0));
	}
	return 0;
}
