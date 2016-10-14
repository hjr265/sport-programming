// In the name of Allah, Most Gracious, Most Merciful

// Matrix Game
// games
// AC (63)

#include <cstdio>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int m, n;
		scanf("%d %d", &m, &n);
		int r = 0;
		while(m--) {
			int h = 0;
			for(int j = 0; j < n; ++j) {
				int x;
				scanf("%d", &x);
				h += x;
			}
			r ^= h;
		}
		printf("Case %d: %s\n", no++, r ? "Alice" : "Bob");
	}
	return 0;
}
