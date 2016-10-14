// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1203
// Guarding Bananas
// geometry
// 
// 
// AC (2012-03-12 14:07:08)

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

#define ALL(c) c.begin(), c.end()

using namespace std;

typedef long long vlong;

const double inf = 1e20;
const double pi = acos(-1.0);

struct Point {
	vlong x, y;
	
	double dist(const Point &r) const {
		return sqrt((x-r.x)*(x-r.x)+(y-r.y)*(y-r.y));
	}
	
	double angle(const Point &p, const Point &q) {
		double A = dist(p), B = dist(q), C = p.dist(q);
		return acos((A*A+B*B-C*C)/(2*A*B));
	}
	
	bool operator==(const Point &p)const{
		return x == p.x && y == p.y;
	}
	
	bool operator!=(const Point &p)const{
		return !(*this == p);
	}
	
	bool operator<(const Point &p)const{
		return x < p.x || x == p.x && y < p.y;
	}
};

vlong cross(const Point &O, const Point &A, const Point &B) {
	return (A.x-O.x)*(B.y-O.y)-(A.y-O.y)*(B.x-O.x);
}

vector<Point> convhull(vector<Point> P) {
	sort(ALL(P));
	P.resize(unique(ALL(P))-P.begin());
	int n = P.size(), k = 0;
	vector<Point> R(2*n);
	vector<Point> T;
	for(int i = 0; i < n; i++) if(i == 0 || P[i-1] != P[i])
		T.push_back(P[i]);
	P = T;
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
		scanf("%d", &n);
		vector<Point> P;
		for(int i = 0; i < n; ++i) {
			Point p;
			scanf("%lld %lld", &p.x, &p.y);
			P.push_back(p);
		}
		vector<Point> R = convhull(P);
		if(R.size() > 1)
			R.pop_back();
		double z = inf;
		for(int i = 2, l = R.size(); i < l+5; ++i)
			z = min(z, R[i%l].angle(R[(i-1)%l], R[(i+1)%l]));
		if(R.size() == 1)
			z = 0;
		printf("Case %d: %0.7lf\n", no++, z/pi*180);
	}
	return 0;
}
