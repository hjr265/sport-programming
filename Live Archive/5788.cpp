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

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main() {
	int no = 1;
	double L[2][2];
	double W[2][2];
	while(scanf("%lf %lf %lf %lf", &L[0][0], &L[0][1], &L[1][0], &L[1][1]) == 4 && (abs(L[0][0]) > EPS || abs(L[0][1]) > EPS || abs(L[1][0]) > EPS || abs(L[1][1]) > EPS)) {
		scanf("%lf %lf %lf %lf", &W[0][0], &W[0][1], &W[1][0], &W[1][1]);
		if(abs(W[0][0]-W[1][0]) < EPS) {
			swap(W[0][0], W[0][1]);
			swap(W[1][0], W[1][1]);
			swap(L[0][0], L[0][1]);
			swap(L[1][0], L[1][1]);
		}
		
		double r = 1/EPS;
		if(L[0][1] < W[0][1] && L[1][1] < W[0][1] || L[0][1] > W[0][1] && L[1][1] > W[0][1]) {
			r = dist(L[0][0], L[0][1], L[1][0], L[1][1]);
		} else {
			r = min(r, dist(L[0][0], L[0][1], W[0][0], W[0][1])+dist(L[1][0], L[1][1], W[0][0], W[0][1]));
			r = min(r, dist(L[0][0], L[0][1], W[1][0], W[1][1])+dist(L[1][0], L[1][1], W[1][0], W[1][1]));
			if(abs(L[0][0]-L[1][0]) > EPS) {
				double c = L[0][0]-(L[1][0]-L[0][0])/(L[1][1]-L[0][1])*L[0][1];
				double x = (L[1][0]-L[0][0])/(L[1][1]-L[0][1])*W[0][1]+c;
				if(x > max(W[0][0], W[1][0]) || x < min(W[0][0], W[1][0]))
					r = min(r, dist(L[0][0], L[0][1], L[1][0], L[1][1]));
			} else {
				if(L[0][0] > max(W[0][0], W[1][0]) || L[0][0] < min(W[0][0], W[1][0]))
					r = min(r, dist(L[0][0], L[0][1], L[1][0], L[1][1]));
			}
		}
		printf("Case %d: %0.3lf\n", no++, r/2);
	}
	return 0;
}
