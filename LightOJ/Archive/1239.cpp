// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1239
// Convex Fence
// geometry
// 
// 
// AC (2012-01-30 23:58:42)

#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>

#define ALL(c) c.begin(), c.end()

using namespace std;

typedef long long vlong;

const double pi = acos(-1.0);

struct Point {
	vlong x, y;
	
	double dist(const Point &r) const {
		return sqrt((x-r.x)*(x-r.x)+(y-r.y)*(y-r.y));
	}
	
	bool operator==(const Point &p)const{
		return x == p.x && y == p.y;
	}
	
	bool operator<(const Point &p)const{
		return x < p.x || x == p.x && y < p.y;
	}
};

vlong cross(const Point &O, const Point &A, const Point &B) {
	return (A.x-O.x)*(B.y-O.y)-(A.y-O.y)*(B.x-O.x);
}

vector<Point> convhull(vector<Point> P) {
	int n = P.size(), k = 0;
	vector<Point> R(2*n);
	sort(ALL(P));
	for(int i = 0; i < n; i++) {
		while(k >= 2 && cross(R[k-2], R[k-1], P[i]) <= 0)
			k--;
		R[k++] = P[i];
	}
	for(int i = n-2, t = k+1; i >= 0; i--) {
		while(k >= t && cross(R[k-2], R[k-1], P[i]) <= 0)
			k--;
		R[k++] = P[i];
	}
	R.resize(k);
	return R;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		vlong d;
		scanf("%d %lld", &n, &d);
		vector<Point> P;
		for(int i = 0; i < n; ++i) {
			Point p;
			scanf("%lld %lld", &p.x, &p.y);
			P.push_back(p);
		}
		vector<Point> R = convhull(P);
		double A = 2*pi*d;
		if(R.size() == 1) 
			R.push_back(R[0]);
		for(int i = 0, l = R.size(); i < l-1; ++i)
			A += R[i].dist(R[i+1]);
		printf("Case %d: %0.5lf\n", no++, A);
	}
	return 0;
}
