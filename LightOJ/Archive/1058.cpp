// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1058
// Parallelogram Counting
// combinatorics, geometry
// 
// 
// AC (2012-05-02 10:55:52)

#include <cstdio>
#include <algorithm>
#include <vector>

#define ALL(c) c.begin(), c.end()

using namespace std;

typedef long long vlong;

struct Point {
	vlong x, y;
	
	Point() {}
	
	Point(vlong x_, vlong y_) : x(x_), y(y_) {}
	
	Point operator+(const Point& r) const {
		return Point(x+r.x, y+r.y);
	}
	
	bool operator==(const Point &r) const {
		return x == r.x && y == r.y;
	}
	
	bool operator<(const Point &r) const {
		return x < r.x || x == r.x && y < r.y;
	}
};

Point P[1002];
vector<Point> M;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%lld %lld", &P[i].x, &P[i].y);
		M.clear();
		for(int i = 0; i < n; ++i) {
			for(int j = i+1; j < n; ++j)
				M.push_back(P[i]+P[j]);
		}
		sort(ALL(M));
		vlong r = 0, t = 1;
		for(int i = 1; i < M.size(); ++i) {
			if(M[i] == M[i-1])
				++t;
			else
				r += (t*(t-1))/2, t = 1;
		}
		printf("Case %d: %lld\n", no++, r);
	}
	return 0;
}
