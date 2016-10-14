// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1328
// A Gift from the Setter
// greedy
// 
// 
// AC (2011-12-09 11:16:27)

#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define SLC(c, n) c, c+(n)

using namespace std;

typedef long long vlong;

const vlong mod = 1000007LL;

vlong a[100002];
vlong s[100002];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong K, C, n;
		scanf("%lld %lld %lld %lld", &K, &C, &n, &a[0]);
		for(int i = 1; i < n; ++i)
			a[i] = (K*a[i-1]+C)%mod;
		sort(SLC(a, n));
		s[0] = a[0];
		for(int i = 1; i < n; ++i)
			s[i] = s[i-1]+a[i];
		vlong r = 0;
		for(int i = 0; i < n; ++i)
			r += abs((a[i]*(n-i-1))-(s[n-1]-s[i]));
		printf("Case %d: %lld\n", no++, r);
	}
	return 0;
}
