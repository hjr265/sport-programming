// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1186
// Incredible Chess
// games
// 
// 
// AC (2011-09-19 11:42:22)

#include <cstdio>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int W[n], B[n];
		for(int i = 0; i < n; ++i)
			scanf("%d", &W[i]);
		for(int i = 0; i < n; ++i)
			scanf("%d", &B[i]);
		int D[n];
		for(int i = 0; i < n; ++i)
			D[i] = B[i] - W[i] - 1;
		int m = 0;
		for(int i = 0; i < n; ++i)
			m ^= D[i];
		printf("Case %d: %s\n", no++, m == 0 ? "black wins" : "white wins");
	}
	return 0;
}
