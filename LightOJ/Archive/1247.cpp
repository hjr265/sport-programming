// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1247
// Matrix Game
// games
// 
// 
// AC (2011-09-19 11:51:18)

#include <cstdio>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		int z = 0;
		while(n--) {
			int r = 0, x;
			for(int i = 0; i < m; ++i, r += x)
				scanf("%d", &x);
			z ^= r;
		}
		printf("Case %d: %s\n", no++, z == 0 ? "Bob" : "Alice");
	}
	return 0;
}
