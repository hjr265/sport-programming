// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1342
// Aladdin and the Magical Sticks
// dp, *probabilities
// 
// 
// AC (2012-05-11 00:56:17)

#include <cstdio>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T-- > 0) {
		int n;
		scanf("%d", &n);
		double r = 0;
		for(int i = 0; i < n; ++i) {
			double a;
			int b;
			scanf("%lf %d", &a, &b);
			if(b == 1) {
				r += a;
			} else {
				for(int j = 1; j <= n; ++j)
					r += a/j;
			}
		}
		printf("Case %d: %0.5lf\n", no++, r);
	}
	return 0;
}
