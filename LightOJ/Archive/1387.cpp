// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1387
// Setu
// implementation
// 
// 
// AC (2012-01-08 15:10:04)

#include <cstdio>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		int r = 0;
		printf("Case %d:\n", no++);
		while(N--) {
			char c[10];
			int K;
			scanf("%s", c);
			switch(c[0]) {
			case 'd':
				scanf("%d", &K);
				r += K;
				break;
			case 'r':
				printf("%d\n", r);
				break;
			}
		}
	}
	return 0;
}
