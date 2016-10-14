// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1015
// Brush (I)
// implementation
// 
// 
// AC (2011-07-26 22:30:02)

#include <cstdio>

typedef long long vlong;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		vlong r = 0;
		while(N--) {
			int x;
			scanf("%d", &x);
			if(x > 0)
				r += x;
		}
		printf("Case %d: %lld\n", no++, r);
	}
	return 0;
}
