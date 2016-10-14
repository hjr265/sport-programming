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

multiset<int> a;

int main() {
	int n, x;
	scanf("%d %d", &n, &x);
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		a.insert(x);
	}
	int z = 0;
	for(int i = 0; i < n; ++i) {
		int bi;
		scanf("%d", &bi);
		
		int y = x-bi;
		multiset<int>::iterator j = a.lower_bound(y);
		
		if(j != a.end()) {
			a.erase(j);
			++z;
		}
	}
	
	printf("1 %d\n", z);
	
	return 0;
}
