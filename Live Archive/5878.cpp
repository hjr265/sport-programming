// In the name of Allah, Most Gracious, Most Merciful

// /
// 
// 
// 
// 
// ??

#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define SET(c, v) memset(c, v, sizeof(c))
#define LEN(c) (sizeof(c)/sizeof(c[0]))
#define ALL(c) c.begin(), c.end()
#define SLC(c, n) c, c+(n)

using namespace std;

typedef unsigned int uint;
typedef long long vlong;
typedef unsigned long long uvlong;

const double EPS = 1e-12;
const double PI = acos(-1.0);

enum {
	
};

int main() {
	int n;
	while(scanf("%d", &n) == 1 && n != 0) {
		vlong x = 0, y = 0;
		double r = 0;
		while(n--) {
			vlong dx, dy;
			scanf("%lld %lld", &dx, &dy);
			vlong x1 = x+dx, y1 = y+dy,
				x2 = x-dx, y2 = y-dy;
			if(x1*x1+y1*y1 > x2*x2+y2*y2)
				x = x1, y = y1;
			else
				x = x2, y = y2;
			r = max(r, sqrt(x*x+y*y));
		}
		printf("%0.3lf\n", r+EPS);
	}
	return 0;
}
