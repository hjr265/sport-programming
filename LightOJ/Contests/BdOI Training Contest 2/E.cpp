// In the name of Allah, Most Gracious, Most Merciful

// Tug of War
// dp
// AC (152)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define CLR(c) memset(c, 0, sizeof(c))
#define SLC(c, n) c, c+n

using namespace std;

typedef long long vlong;

int W[100+2];
vlong S[100000+2];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int z = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &W[i]);
			z += W[i];
		}
		sort(SLC(W, n));
		CLR(S);
		S[0] = 1;
		for(int i = 0; i < n; ++i) {
			for(int j = z; j >= W[i]; --j)
				S[j] |= S[j-W[i]]<<1;
		}
		int l = 0, h = 1<<30;
		for(int i = 0; i <= z; ++i) {
			for(int j = 0; j <= n/2+1; ++j) {
				if(abs(n-2*j) <= 1 && (S[i]&(1LL<<j)) != 0 && abs(z-2*i) < h-l) {
					l = min(i, z-i);
					h = max(i, z-i);
				}
			}
		}
		printf("Case %d: %d %d\n", no++, l, h);
	}
	return 0;
}
