// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/2189
// Mobile Casanova
// implementation
// 
// 
// AC (2011-10-04 10:38:17)

#include <cstdio>

typedef long long vlong;

int main() {
	int no = 1, n;
	while(scanf("%d", &n) == 1 && n != 0) {
		printf("Case %d:\n", no++);
		vlong p, q, r = 0;
		scanf("%lld", &p);
		bool t = true;
		while(n--) {
			if(n > 0)
				scanf("%lld", &q);
			else
				q = 2000000005;
			if(q - p != 1) {
				if(r > 0) {
					printf("0%d-", p - r);
					char b[20], c[20];
					sprintf(b, "%lld", p - r);
					sprintf(c, "%lld", p);
					for(int i = 0; c[i]; ++i) if(b[i] != c[i]) {
						for(; c[i]; ++i)
							printf("%c", c[i]);
						break;
					}
					printf("\n");
				} else {
					printf("0%lld\n", p);
				}
				r = 0;
			} else {
				++r;
			}
			p = q;
		}
		printf("\n");
	}
	return 0;
}
