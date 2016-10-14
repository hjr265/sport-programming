// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1253
// Misere Nim
// games
// 
// 
// AC (2011-09-21 16:37:29)

#include <cstdio>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int k;
		scanf("%d", &k);
		int r = 0;
		bool o = true;
		for(int i = 0, x; i < k; ++i, r ^= x, o = o && x == 1)
			scanf("%d", &x);
		printf("Case %d: %s\n", no++, ((o && (k & 1) == 1) || (!o && r == 0)) ? "Bob" : "Alice");
	}
	return 0;
}
