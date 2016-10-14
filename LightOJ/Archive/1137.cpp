// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1137
// Expanding Rods
// binary search, geometry
// 
// 
// AC (2012-01-10 01:31:34)

#include <cmath>
#include <cstdio>

const double pi = acos(-1.0);

double arclen(double L, double t) {
	return ((L/2)/sin(t/2))*t;
}

double height(double L, double t) {
	return ((L/2)/sin(t/2))-(L/2)/tan(t/2);
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		double L, n, C;
		scanf("%lf %lf %lf", &L, &n, &C);
		double Lp = (1+n*C)*L;
		double l = 0.0, h = pi, m;
		while(l < h) {
			m = (l+h)/2;
			if(arclen(L, m) < Lp)
				l = m+1e-8;
			else
				h = m-1e-8;
		}
		printf("Case %d: %0.8lf\n", no++, height(L, m));
	}
	return 0;
}
