// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1072
// Calm Down
// *binary search, *geometry, implementation
// 
// 
// AC (2011-09-19 21:04:18)

#include <cstdio>
#include <cmath>

const double pi = acos(-1.0);
const double eps = 1e-12;

double fn(double R, double n, double r) {
	return ((R-r)*(R-r)+(R-r)*(R-r)-2*(R-r)*(R-r)*cos(2.0*pi/n))-((2*r)*(2*r));
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		double R;
		int n;
		scanf("%lf %d", &R, &n);
		if(n == 2) {
			printf("Case %d: %lf\n", no++, R/2);
			continue;
		}
		double l = 0.0, h = R, r;
		while(l < h) {
			r = (l+h)/2;
			if(fn(R, n, l)*fn(R, n, r) <= 0)
				h = r - eps;
			else
				l = r + eps;
		}
		printf("Case %d: %lf\n", no++, r);
	}
	return 0;
}
