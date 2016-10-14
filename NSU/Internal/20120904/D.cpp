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

vlong n, d;

vlong P[1005];

void initP() {
	P[0] = 1%d;
	for(vlong i = 1; i < 1005; ++i)
		P[i] = (P[i-1]*10)%d;
}

vlong R[1002];

void initR() {
	SET(R, 0);
	R[n-1] = 1;
}

vlong modR() {
	vlong r = 0;
	for(int i = 0; i < 1005; ++i)
		r += (R[i]*P[i])%d, r %= d;
	return r ? r : d;
}

void addR(vlong x) {
	vlong e = 0;
	for(int i = 0; i < 1005; ++i, x /= 10) {
		R[i] += x%10+e;
		e = R[i]/10;
		R[i] %= 10;
	}
}

bool validR() {
	for(int i = n; i < 1005; ++i) if(R[i] != 0)
		return false;
	return true;
}

void printR() {
	for(int i = n-1; i >= 0; --i)
		printf("%d", R[i]);
	printf("\n");
}

int main() {
	scanf("%lld %lld", &n, &d);
	initP();
	initR();
	addR(d-modR());
	if(validR())
		printR();
	else
		printf("No solution\n");
	return 0;
}
