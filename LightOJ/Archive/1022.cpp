// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1022
// Circle in Square
// geometry
// 
// 
// AC (2011-07-26 22:43:57)

#include <cmath>
#include <cstdio>

const double pi = acos(-1.0);

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		double r;
		scanf("%lf", &r);
		printf("Case %d: %0.2lf\n", no++, (4-pi)*r*r);
	}
	return 0;
}
