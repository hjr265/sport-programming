// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1127
// Funny Knapsack
// binary search
// 
// 
// AC (2012-05-27 00:10:04)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define CLR(c) memset(c, 0, sizeof(c))
#define SLC(c, n) c, c+(n)

using namespace std;

typedef long long vlong;

vlong A[32];
vlong L[(1<<16)+5];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		vlong W;
		scanf("%d %lld", &n, &W);
		for(int i = 0; i < n; ++i)
			scanf("%lld", &A[i]);
		CLR(L);
		for(int i = 0; i < 1<<(n/2+n%2); ++i) {
			for(int j = 0, x = i; j < n/2+n%2; ++j, x /= 2)
				L[i] += A[j]*(x%2);
		}
		sort(SLC(L, 1<<(n/2+n%2)));
		int z = 0;
		for(int i = 0; i < 1<<(n-n/2-n%2); ++i) {
			vlong R = 0;
			for(int j = n/2+n%2, x = i; j < n; ++j, x /= 2)
				R += A[j]*(x%2);
			z += upper_bound(SLC(L, 1<<(n/2+n%2)), W-R)-L;
		}
		printf("Case %d: %d\n", no++, z);
	}
	return 0;
}
