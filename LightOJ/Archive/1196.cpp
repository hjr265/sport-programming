// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1196
// Inhabitants
// binary search
// 
// 
// AC (2012-01-31 12:17:38)

#include <cstdio>
#include <vector>

using namespace std;

typedef long long vlong;

struct Point {
	vlong x, y;
	
	Point() {}
	
	Point(vlong x_, vlong y_) : x(x_), y(y_) {}
	
	vlong cross(const Point &a, const Point &b) {
		return x*a.y+a.x*b.y+b.x*y-y*a.x-a.y*b.x-b.y*x;
	}
};

vector<Point> V;

bool inside(const Point &p) {
	int l = 0, h = V.size()-1, m;
	while(l < h) {
		m = (l+h)/2;
		if(V[0].cross(V[m], p) >= 0)
			l = m+1;
		else
			h = m;
	}
	if(m >= 1 && m < V.size()-1 && V[0].cross(V[m], p) >= 0 && V[m].cross(V[m+1], p) >= 0 && V[m+1].cross(V[0], p) >= 0)
		return true;
	if(m > 1 && m <= V.size() && V[0].cross(V[m-1], p) >= 0 && V[m-1].cross(V[m], p) >= 0 && V[m].cross(V[0], p) >= 0)
		return true;
	return false;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		V.clear();
		for(int i = 0; i < n; ++i) {
			Point p;
			scanf("%lld %lld", &p.x, &p.y);
			V.push_back(p);
		}
		int Q;
		scanf("%d", &Q);
		printf("Case %d:\n", no++);
		while(Q--) {
			Point p;
			scanf("%lld %lld", &p.x, &p.y);
			printf("%c\n", inside(p) ? 'y' : 'n');
		}
	}
	return 0;
}
