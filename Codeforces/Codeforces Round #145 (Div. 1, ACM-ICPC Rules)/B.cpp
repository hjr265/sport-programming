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
int a, b;
int h[202];
int w[202];

int D[202][40002][2];

int dp(int i, int ar, int c) {
	int au = a-ar;
	int bu = w[i]-au,
		br = b-bu;
	
	if(ar < 0 || br < 0)
		return 1<<28;
	if(i > n)
		return 0;
	
	int &r = D[i][ar][c];
	if(r == -1) {
		r = 1<<28;
		if(c == 0) {
			r = min(r, dp(i+1, ar-h[i], c));
			r = min(r, dp(i+1, ar, 1-c)+min(h[i-1], h[i]));
		} else {
			r = min(r, dp(i+1, ar, c));
			r = min(r, dp(i+1, ar-h[i], 1-c)+min(h[i-1], h[i]));
		}
	}
	
	return r;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &h[i]);
	for(int i = 1; i <= n; ++i)
		w[i+1] = w[i]+h[i];
	
	SET(D, -1);
	int r = dp(0, a, 0);
	printf("%d\n", r == 1<<28 ? -1 : r);
	return 0;
}
