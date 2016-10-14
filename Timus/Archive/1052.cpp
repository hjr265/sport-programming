// In the name of Allah, Most Gracious, Most Merciful

// Timus/1052
// Rabbit Hunt
// geometry
// 
// 
// AC (15:41:50 24 May 2012)

#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>

#define ALL(c) c.begin(), c.end()

using namespace std;

const double eps = 1e-12;
const double pi = acos(-1.0);

struct Point {
	double x, y;
	
	double angle(const Point &r) const {
		double t = atan2(r.y-y, r.x-x);
		while(t < pi)
			t += pi;
		while(t > 0)
			t -= pi;
		return t;
	}
};

Point P[202];

int main() {
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%lf %lf", &P[i].x, &P[i].y);
	int r = 1;
	for(int i = 0; i < N; ++i) {
		vector<double> x;
		for(int j = 0; j < N; ++j) if(i != j)
			x.push_back(P[i].angle(P[j]));
		sort(ALL(x));
		int t = 1;
		for(int j = 1; j < x.size(); ++j) {
			if(fabs(x[j]-x[j-1]) < eps)
				r = max(r, ++t);
			else
				t = 1;
		}
	}
	printf("%d\n", r+1);
	return 0;
}
