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

int n = 4;
int a[100002] = {2, 1, 3, 4};
int b[100002] = {3, 4, 2, 1};
int x[100002];


int main() {
	set<pair<int, int> > s;
	for(int i = 0; i < n; ++i)
		x[a[i]] = i;
	for(int i = 0; i < n; ++i)
		s.insert(pair<int, int>(abs(i-x[b[i]]), b[i]));
	for(int i = 0; i < n; ++i) {
		
		
		
		
		printf("%d\n", s.begin()->first);
	}
	return 0;
}
