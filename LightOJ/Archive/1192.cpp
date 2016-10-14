// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1192
// Left Right
// games
// 
// 
// AC (2011-09-19 11:47:43)

#include <cstdio>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int k;
		scanf("%d", &k);
		int m = 0;
		while(k--) {
			int g, w;
			scanf("%d %d", &g, &w);
			m ^= w - g - 1;
		}
		printf("Case %d: %s\n", no++, m == 0 ? "Bob" : "Alice");
	}
	return 0;
}
