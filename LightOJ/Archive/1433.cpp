// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1433
// Minimum Arc Distance
// geometry
// 
// 
// AC (2012-05-27 19:59:59)

#include <cmath>
#include <cstdio>

const double pi = acos(-1.0);

struct Point {
	double x, y;
	
	double dist(const Point &r) const {
		return sqrt((x-r.x)*(x-r.x)+(y-r.y)*(y-r.y));
	}
};

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		Point O, A, B;
		scanf("%lf %lf %lf %lf %lf %lf", &O.x, &O.y, &A.x, &A.y, &B.x, &B.y);
		double t = acos((O.dist(A)*O.dist(A)+O.dist(B)*O.dist(B)-A.dist(B)*A.dist(B))/(2*O.dist(A)*O.dist(B)));
		while(t > pi)
			t -= pi;
		while(t < 0)
			t += pi;
		printf("Case %d: %0.4lf\n", no++, t*O.dist(A));
	}
	return 0;
}
