// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1374
// Confusion in the Problemset
// greedy
// 
// 
// AC (2012-01-06 00:52:34)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

bool p[1000002];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		CLR(p);
		bool f = true;
		for(int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			if(x < n && x >= 0) {
				if(!p[x]) {
					p[x] = true;
					continue;
				}
				if(!p[n-x-1]) {
					p[n-x-1] = true;
					continue;
				}
			}
			f = false;
		}
		printf("Case %d: %s\n", no++, f ? "yes" : "no");
	}
	return 0;
}
