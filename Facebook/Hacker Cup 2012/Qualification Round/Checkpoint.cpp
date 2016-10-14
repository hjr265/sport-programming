// In the name of Allah, Most Gracious, Most Merciful

// Checkpoint
// combinatorics, dp
// AC (22:05)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define CLR(c) memset(c, 0, sizeof(c))

typedef long long vlong;

const int Smax = 10000052;

vlong C[Smax+2];
vlong Q[Smax+2];
vlong T[Smax+2];

void gen() {
	for(int i = 0; i < Smax; ++i)
		Q[i] = i, T[i] = 1LL<<60;
	CLR(C);
	for(vlong cx = 0; cx < Smax; ++cx) {
		for(vlong cy = 0; cy < Smax; ++cy) {
			if(cx == 0 || cy == 0)
				C[cy+1] = 1;
			else
				C[cy+1] += C[cy+1-1];
			if(cx+cy == 0)
				continue;
			vlong cw = C[cy+1];
			if(cw > Smax)
				break;
			Q[cw] = min(Q[cw], cx+cy);
		}
	}
	for(vlong cw = 1; cw <= Smax; ++cw) {
		for(vlong gw = 1; cw*gw <= Smax; ++gw)
			T[cw*gw] = min(T[cw*gw], Q[cw]+Q[gw]);
	}
}

int main() {
	gen();
	int R, no = 1;
	scanf("%d", &R);
	while(R--) {
		int S;
		scanf("%d", &S);
		printf("Case #%d: %lld\n", no++, T[S]);
	}
	return 0;
}
