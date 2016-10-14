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
	int x, y, z;
	cin >> x >> y >> z;
	int x1, y1, z1;
	cin >> x1 >> y1 >> z1;
	
	int r = 0;
	for(int i = 0; i < 6; ++i) {
		int a;
		cin >> a;
		
		switch(i) {
		case 0:
			if(y < 0)
				r += a;
			break;
		case 1:
			if(y > y1)
				r += a;
			break;
		case 2:
			if(z < 0)
				r += a;
			break;
		case 3:
			if(z > z1)
				r += a;
			break;
		case 4:
			if(x < 0)
				r += a;
			break;
		case 5:
			if(x > x1)
				r += a;
			break;
		}
	}
	
	cout << r << endl;
	return 0;
}
