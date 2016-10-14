// In the name of Allah, Most Gracious, Most Merciful

// Positive Negative Sign
// math
// AC (59)

#include <cstdio>

typedef long long vlong;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong n, m;
		scanf("%lld %lld", &n, &m);
		printf("Case %d: %lld\n", no++, (n*m)/2);
	}
	return 0;
}
