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

vlong D[] = {1LL, 0LL, 1LL, 2LL, 9LL, 44LL, 265LL, 1854LL, 14833LL, 133496LL, 1334961LL, 14684570LL, 176214841LL, 2290792932LL, 32071101049LL, 481066515734LL, 7697064251745LL, 130850092279664LL, 2355301661033953LL, 44750731559645106LL, 895014631192902121LL, 18795307255050944540LL};

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		cout << D[n] << endl;
	}
	return 0;
}
