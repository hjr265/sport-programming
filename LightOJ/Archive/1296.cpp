// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1296
// Again Stone Game
// games
// 
// 
// AC (2012-01-10 22:38:34)

#include <cstdio>

int grundy(int n) {
	return n%2 ? grundy(n/2) : n/2;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int r = 0;
		for(int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			r ^= grundy(x);
		}
		printf("Case %d: %s\n", no++, r ? "Alice" : "Bob");
	}
	return 0;
}
