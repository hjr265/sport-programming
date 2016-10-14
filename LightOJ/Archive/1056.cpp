// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1056
// Olympics
// binary search, geometry
// 
// 
// AC (2011-10-25 02:31:54)

#include <cstdio>
#include <cmath>

const double eps = 1e-8;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		double a, b;
		scanf("%lf : %lf", &a, &b);
		double t = atan(b/a);
		double l = 0, h = 1000, r;
		while(fabs(h-l) > eps) {
			r = (l+h)/2;
			double w = 2*r*sin(t), g = 2*r*cos(t);
			if((2*g+2*(r*t*2)) < 400.0)
				l = r;
			else
				h = r;
		}
		printf("Case %d: %.8lf %.8lf\n", no++, 2*r*cos(t), 2*r*sin(t));
	}
	return 0;
}
