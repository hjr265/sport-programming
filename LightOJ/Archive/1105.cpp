// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1105
// Fi Binary Number
// dp, *greedy
// 
// 
// AC (2012-03-12 16:07:13)

#include <cstdio>

int F[45];

int main() {
	F[0] = 1;
	F[1] = 2;
	for(int i = 2; i < 45; ++i)
		F[i] = F[i-1]+F[i-2];
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		printf("Case %d: ", no++);
		for(int i = 44; i >= 0; --i) if(F[i] <= n) {
			for(int j = i; j >= 0; --j) {
				if(F[j] <= n) {
					n -= F[j];
					printf("1");
				} else {
					printf("0");
				}
			}
			break;
		}
		printf("\n");
	}
	return 0;
}
