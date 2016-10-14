// In the name of Allah, Most Gracious, Most Merciful

// Timus/1020
// Rope
// geometry
// 
// 
// AC (15:15:35 24 May 2012)

#include <cmath>
#include <cstdio>

const double pi = acos(-1.0);

struct Point {
	double x, y;
	
	double dist(const Point &r) const {
		return sqrt((x-r.x)*(x-r.x)+(y-r.y)*(y-r.y));
	}
};

int N;
double R;
Point P[102];

int main() {
	scanf("%d %lf", &N, &R);
	for(int i = 0; i < N; ++i)
		scanf("%lf %lf", &P[i].x, &P[i].y);
	P[N] = P[0];
	double Z = 0;
	for(int i = 0; i < N; ++i)
		Z += P[i].dist(P[i+1]);
	printf("%0.2lf\n", Z+2*pi*R);
	return 0;
}
