// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/4889
// Post Office
// implementation
// 
// 
// AC (2011-08-09 10:24:11)

#include <cstdio>
#include <algorithm>

#define SLC(c, n) c, c+n

using namespace std;

const double eps = 1e-12;

int main() {
	double d[3];
	while(scanf("%lf %lf %lf", &d[0], &d[1], &d[2]) == 3 && (d[0] > eps || d[1] > eps || d[2] > eps)) {
		sort(SLC(d, 3));
		if(d[2] >= 125.0 && d[1] >= 90.0 && d[0] >= 0.25) {
			if(d[2] <= 290.0 && d[1] <= 155.0 && d[0] <= 7.0)
				printf("letter\n");
			else if((d[2] > 290.0 || d[1] > 155.0 || d[0] > 7.0) && d[2] <= 380.0 && d[1] <= 300.0 && d[0] <= 50.0)
				printf("packet\n");
			else if((d[2] > 380.0 || d[1] > 300.0 || d[0] > 50.0) && 2*(d[1]+d[0])+d[2] <= 2100.0)
				printf("parcel\n");
			else
				printf("not mailable\n");
		} else {
			printf("not mailable\n");
		}
	}
	return 0;
}
