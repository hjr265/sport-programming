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
	PSmax = 10000005
};

int PV[PSmax];
int PS[PSmax];
bool S[PSmax];

int a, b, k;

void pseive() {
	PV[2] = 1;
	PS[2] = 1;
	for(vlong i = 3; i < PSmax; i += 2) if(!S[i]) {
		PV[i] = 1;
		PS[i] = 1;
		for(vlong j = i*i; j < PSmax; j += 2*i)
			S[j] = true;
	}
}

bool okay(int l) {
	l = min(l, b-a+1);
	int c = PS[a+l-1]-PS[a-1];
	for(int i = a+l; i <= b && c >= k; ++i)
		c += -PV[i-l]+PV[i];
	return c >= k;
}

int main() {
	pseive();
	for(int i = 1; i < PSmax; ++i)
		PS[i] += PS[i-1];
	
	scanf("%d %d %d", &a, &b, &k);
	
	int l = 0, h = b-a+2;
	while(h-l > 10) {
		int m = (l+h)/2;
		if(okay(m))
			h = m;
		else
			l = m;
	}
	bool f = true;
	for(; f && l <= h; ++l) if(l >= 1 && l <= b-a+1 && okay(l)) {
		printf("%d\n", l);
		f = false;
	}
	if(f)
		printf("-1\n");
	return 0;
}
