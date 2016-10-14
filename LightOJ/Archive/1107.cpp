// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1107
// How Cow
// geometry
// 
// 
// AC (2011-07-26 23:39:06)

#include <cstdio>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		printf("Case %d:\n", no++);
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int M;
		scanf("%d", &M);
		while(M-- > 0) {
			int x, y;
			scanf("%d %d", &x, &y);
			printf("%s\n", x >= x1 && x <= x2 && y >= y1 && y <= y2 ? "Yes" : "No");
		}
	}
	return 0;
}
