// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1202
// Bishops
// implementation
// 
// 
// AC (2011-09-19 20:34:02)

#include <cstdio>
#include <cstdlib>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int r1, c1, r2, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		if((r1+c1)%2 != (r2+c2)%2)
			printf("Case %d: %s\n", no++, "impossible");
		else
			printf("Case %d: %d\n", no++, abs(r1-r2) == abs(c1-c2) ? 1 : 2);
	}
	return 0;
}
