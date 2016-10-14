// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1331
// Agent J
// geometry
// 
// 
// AC (2011-10-17 02:13:16)

#include <cmath>
#include <cstdio>

double theta(double a, double b, double c) {
	return acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2.0 * a * b));
}

double sect(double r, double t) {
	return 0.5 * pow(r, 2) * t;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		double r[3];
		scanf("%lf %lf %lf", &r[0], &r[1], &r[2]);
		double s[] = {r[1]+r[2], r[0]+r[2], r[0]+r[1]},
			t[] = {theta(s[1], s[2], s[0]), theta(s[0], s[2], s[1]), theta(s[0], s[1], s[2])},
			a[] = {sect(r[0], t[0]), sect(r[1], t[1]), sect(r[2], t[2])};
		printf("Case %d: %lf\n", no++, 0.5*s[0]*s[1]*sin(t[2])-a[0]-a[1]-a[2]);
	}
	return 0;
}
