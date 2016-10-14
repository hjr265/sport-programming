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

bool x[205];

int main() {
	int no = 1;
	int s, c, p, l;
	while(scanf("%d %d %d %d", &s, &c, &p, &l) == 4 && (s != 0 || c != 0 || p != 0 || l != 0)) {
		int r = 0;
		r = s-p;
		int i = r%c;
		SET(x, 0);
		bool k = true;
		while(!x[i] && k) {
			if(c-i == l) {
				k = false;
				break;
			}
			x[i] = true;
			r += s;
			i = r%c;
		}
		printf("Case %d: ", no++);
		if(!k)
			printf("%d %d/%d\n", r/s, r%s, s);
		else
			printf("Never\n");
	}
	return 0;
}
