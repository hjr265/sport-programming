// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1045
// Digits of Factorial
// number theory
// 
// 
// AC (2011-07-26 23:20:50)

#include <cmath>
#include <cstdio>

typedef long long vlong;

double g[1000005];

int main() {
	g[1] = log(1);
	for(int i = 2; i < 1000005; ++i)
		g[i] = g[i-1]+log(i);
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, base;
		scanf("%d %d", &n, &base);
		printf("Case %d: %lld\n", no++, n == 0 ? 1LL : (vlong)(g[n]/log(base)+1));
	}
	return 0;
}
