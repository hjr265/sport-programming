// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/5737
// Pills
// dp
// 
// 
// AC (2012-01-21 12:20:33)

#include <cstdio>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

typedef long long vlong;

vlong mo[62][32][32];

vlong dp(int N, int W, int H) {
	if(N == 0)
		return 1;
	vlong &r = mo[N][W][H];
	if(r == -1) {
		r = 0;
		if(W)
			r += dp(N-1, W-1, H);
		if(H)
			r += dp(N-1, W, H-1);
	}
	return r;
}

int main() {
	SET(mo);
	int N;
	while(scanf("%d", &N) && N != 0)
		printf("%lld\n", dp(2*N, N, N)/(N+1));
	return 0;
}
