// In the name of Allah, Most Gracious, Most Merciful

// TopCoder/SRM 547 Div 2/250
// Minimal Triangle
// geometry
// http://community.topcoder.com/stat?c=problem_statement&pm=12056&rd=14739
// (MinimalTriangle) maximalArea(int) double
// AC (242)

#include <cmath>

const double pi = acos(-1.0);

class MinimalTriangle {
public:
	double maximalArea(int length) {
		return 0.5*length*length*sin(pi/180*120);
	}
};

int main() {
	return 0;
}
