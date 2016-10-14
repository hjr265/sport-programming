// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1371
// Energetic Pandas
// combinatorics
// 
// 
// AC (2012-05-25 20:51:22)

#include <cstdio>
#include <algorithm>

#define SLC(c, n) c, c+n

using namespace std;

typedef long long vlong;

const vlong mod = 1000000007LL;

int W[1002], C[1002];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &W[i]);
		sort(SLC(W, n));
		for(int i = 0; i < n; ++i)
			scanf("%d", &C[i]);
		sort(SLC(C, n));
		vlong r = 1;
		for(int i = n-1; i >= 0; --i) {
			if(W[i] > C[i]) {
				r = 0;
				break;
			}
			vlong t = 0;
			for(int j = i; j >= 0 && W[i] <= C[j]; --j)
				++t;
			r = (r*t)%mod;
		}
		printf("Case %d: %lld\n", no++, r);
	}
	return 0;
}
