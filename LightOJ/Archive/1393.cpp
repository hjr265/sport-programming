// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1393
// Crazy Calendar
// games
// 
// 
// AC (2012-01-15 01:34:46)

#include <cstdio>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int R, C;
		scanf("%d %d", &R, &C);
		int r = 0;
		for(int i = R-1; i >= 0; --i) {
			for(int j = C-1; j >= 0; --j) {
				int x;
				scanf("%d", &x);
				if((i+j)%2)
					r ^= x;
			}
		}
		printf("Case %d: %s\n", no++, r ? "win" : "lose");
	}
	return 0;
}
