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
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int X1, X2, Y1, Y2;
		scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
		if(X1 == X2) {
			++X1;
			--X2;
		} else {
			if(Y1 > Y2)
				--Y1, ++Y2;
			else
				++Y1, --Y2;
		}
		printf("Case %d: %d %d %d %d\n", no++, X1, Y1, X2, Y2);
	}
	return 0;
}
