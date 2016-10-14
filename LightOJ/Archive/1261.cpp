// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1261
// K-SAT Problem
// implementation
// 
// 
// AC (2011-08-09 22:33:26)

#include <cstdio>

typedef long long vlong;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, m, K;
		scanf("%d %d %d", &n, &m, &K);
		int g[n][K];
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < K; ++j)
				scanf("%d", &g[i][j]);
		vlong s = 0;
		int p;
		scanf("%d", &p);
		for(int i = 0; i < p; ++i) {
			int x;
			scanf("%d", &x);
			s |= 1<<x;
		}
		bool f = true;
		for(int i = 0; i < n && f; ++i) {
			bool h = false;
			for(int j = 0; j < K; ++j) {
				int x = g[i][j];
				if(x > 0 && (s&(1LL<<x)) > 0 || x < 0 && (s&(1LL<<-x)) == 0) {
					h = true;
					break;
				}
			}
			if(!h)
				f = false;
		}
		printf("Case %d: %s\n", no++, f ? "Yes" : "No");
	}
	return 0;
}
