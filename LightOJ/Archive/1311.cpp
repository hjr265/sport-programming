// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1311
// Unlucky Bird
// math
// 
// 
// AC (2011-11-10 15:00:08)

#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		double v1, v2, v3, a1, a2;
		scanf("%lf %lf %lf %lf %lf", &v1, &v2, &v3, &a1, &a2);
		double t1 = v1/a1, t2 = v2/a2;
		printf("Case %d: %0.8lf %0.8lf\n", no++, 0.5*a1*t1*t1 + 0.5*a2*t2*t2, v3*max(t1, t2));
	}
	return 0;
}
