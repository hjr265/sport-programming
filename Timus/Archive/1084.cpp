// In the name of Allah, Most Gracious, Most Merciful

// Timus/1084
// Goat in the Garden
// geometry
// 
// 
// AC (15:31:22 24 May 2012)

#include <cmath>
#include <cstdio>

const double pi = acos(-1.0);

int main() {
	double L, R;
	scanf("%lf %lf", &L, &R);
	if(R <= L/2) {
		printf("%0.3lf\n", pi*R*R);
	} else if(R >= sqrt(L*L*2)/2) {
		printf("%0.3lf\n", L*L);
	} else {
		double t = acos(L/(2*R));
		printf("%0.3lf\n", R*R*(pi-4*(t-0.5*sin(t*2))));
	}
	return 0;
}
