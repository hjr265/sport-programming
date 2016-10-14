// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1346
// Aladdin and the Rocky Mountains
// geometry
// 
// 
// AC (2012-02-04 00:11:11)

#include <cmath>
#include <cstdio>

typedef long long vlong;

struct Point {
	vlong x, y;
	
	Point() : x(0), y(0) {}
	
	Point(vlong x_, vlong y_) : x(x_), y(y_) {}
	
	double dist(const Point &r) {
		return sqrt((x-r.x)*(x-r.x)+(y-r.y)*(y-r.y));
	}
};

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		Point a;
		scanf("%d %lld", &n, &a.x);
		double u = 0, v = 0;
		Point t;
		double r = 0;
		while(n--) {
			Point p;
			scanf("%lld %lld", &p.x, &p.y);
			double w = atan2(p.y, p.x-a.x);
			if(w > v) {
				r += t.dist(p)-(sin(v-u)*a.dist(t)/sin(atan2(p.y-t.y, p.x-t.x)-v));
				v = w;
			}
			t = p;
			u = w;
		}
		printf("Case %d: %0.4lf\n", no++, r);
	}
	return 0;
}
