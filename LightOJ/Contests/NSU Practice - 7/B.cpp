// In the name of Allah, Most Gracious, Most Merciful

// Misere Nim
// games
// AC (72)

#include <cstdio>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int k;
		scanf("%d", &k);
		int r = 0;
		bool m = true;
		for(int i = 0; i < k; ++i) {
			int h;
			scanf("%d", &h);
			if(h != 1)
				m = false;
			r ^= h;
		}
		printf("Case %d: %s\n", no++, (m && k%2 == 0 || !m && r) ? "Alice" : "Bob");
	}
	return 0;
}
