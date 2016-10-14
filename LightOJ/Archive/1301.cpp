// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1301
// Monitoring Processes
// greedy
// 
// 
// AC (2011-09-19 15:30:54)

#include <cstdio>
#include <algorithm>

#define SLC(c, n) c, c+(n)

using namespace std;

const int inf = 1234567890;

int s[50005], t[50005];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d %d", &s[i], &t[i]);
		sort(SLC(s, n));
		s[n] = inf;
		sort(SLC(t, n));
		t[n] = inf;
		int z = 0;
		for(int i = 0, j = 0, c = 0, k = 0; ; ) {
			if(s[i] <= t[j])
				c = s[i++], ++k;
			else
				c = t[j++], --k;
			if(i == n && j == n)
				break;
			z = max(z, k);
		}
		printf("Case %d: %d\n", no++, z);
	}
	return 0;
}
