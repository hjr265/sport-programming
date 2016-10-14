// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1216
// Juice in the Glass
// geometry
// 
// 
// AC (2011-09-19 20:17:04)

#include <cmath>
#include <cstdio>

const double pi = acos(-1.0);

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		double r1, r2, h, p;
		scanf("%lf %lf %lf %lf", &r1, &r2, &h, &p);
		double H = h/(r1-r2)*r1, P = p+H-h;
		double r3 = r1-(h-p)*r1/H;
		printf("Case %d: %lf\n", no++, pi*r3*r3*P/3.0-pi*r2*r2*(P-p)/3.0);
	}
	return 0;
}
