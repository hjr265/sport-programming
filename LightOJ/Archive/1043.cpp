// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1043
// Triangle Partitioning
// binary search, geometry
// 
// 
// AC (2011-09-05 11:22:47)

#include <cmath>
#include <cstdio>

const double eps = 1e-7;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		double AB, AC, BC, r;
		scanf("%lf %lf %lf %lf", &AB, &AC, &BC, &r);
		double A = acos((pow(AB, 2)+pow(AC, 2)-pow(BC, 2))/(2*AB*AC)), ABC = 0.5*AB*AC*sin(A);
		double ADl = eps, ADu = AB-eps, AD;
		while(ADu-ADl > eps) {
			AD = (ADl+ADu)/2;
			double AE = AC*AD/AB, ADE = 0.5*AD*AE*sin(A), BDEC = ABC-ADE;
			if(ADE/BDEC > r)
				ADu = AD-eps;
			else
				ADl = AD+eps;
		}
		printf("Case %d: %lf\n", no++, AD);
	}
}
