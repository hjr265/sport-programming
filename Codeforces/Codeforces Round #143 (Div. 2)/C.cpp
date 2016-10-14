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

int n;
vlong k;
vlong a[100005];

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(SLC(a, n));
	a[n] = a[n-1];
	
	vlong x = 0;
	pair<int, int> z(0, 0);
	for(int i = 0, j = 0; i < n && j < n; ) {
		if(x > k) {
			x -= a[j]-a[i];
			++i;
		} else {
			if(j-i+1 > z.first)
				z = pair<int, int>(j-i+1, a[j]);
			++j;
			x += (a[j]-a[j-1])*(j-i);
		}
	}
	
	cout << z.first << " " << z.second << endl;
	return 0;
}
