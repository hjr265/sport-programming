// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1248
// Dice (III)
// probabilities
// 
// 
// AC (2012-01-28 20:32:36)

#include <cstdio>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		double r = n;
		for(int i = n-1; i; --i)
			r += ((double)i/(double)n)/(double)(1-((double)i/(double)n));
		printf("Case %d: %0.7lf\n", no++, r);
	}
	return 0;
}
