// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1116
// Ekka Dokka
// math
// 
// 
// AC (2011-09-19 22:12:42)

#include <cstdio>

typedef long long vlong;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong W;
		scanf("%lld", &W);
		if((W&1) == 0) {
			vlong M = 1;
			while((W&1) == 0)
				W >>= 1, M <<= 1;
			printf("Case %d: %lld %lld\n", no++, W, M);
		} else {
			printf("Case %d: Impossible\n", no++);
		}
	}
	return 0;
}
