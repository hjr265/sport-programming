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

vlong a, b, p, q;

vlong solve(vlong n, vlong p, vlong q) {
	vlong r = 0;
	for(int i = 1; i < 62; ++i) {
		vlong t = n;
		for(int j = 0; j < i; ++j)
			t /= p;
		for(int j = 0; j < i; ++j) {
			vlong y = t;
			for(int k = 0; k < j; ++k)
				y /= q;
			r += y-y/p-y/q+(y/p)/q;
		}
	}
	return r;
}

int main() {
	scanf("%lld %lld %lld %lld", &a, &b, &p, &q);
	cout << solve(b, p, q)-solve(a-1, p, q) << endl;
	return 0;
}
