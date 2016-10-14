// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/4853
// Emoogle Balance
// implementation
// 
// 
// AC (2011-10-05 07:16:07)

#include <cstdio>

int main() {
	int N, no = 1;
	while(scanf("%d", &N) == 1 && N != 0) {
		int r = 0;
		for(int i = 0, x; i < N; ++i, r += x == 0 ? -1 : 1)
			scanf("%d", &x);
		printf("Case %d: %d\n", no++, r);
	}
	return 0;
}
