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

struct State {
	int v, x, y;
	
	State() {}
	State(int v_, int x_, int y_) : v(v_), x(x_), y(y_) {}
};

int n, d, l;

State M[102][20005];

State dp(int i, int j) {
	if(i == 0)
		return State(j == d, -1, -1);
	State &r = M[i][j+10002];
	if(r.v == -1) {
		r.v = 0;
		for(int k = 1; k <= l; ++k) {
			State t = dp(i-1, k-j);
			if(t.v > r.v) {
				r.v = 1;
				r.x = k;
				r.y = j;
			}
		}
	}
	return r;
}

int main() {
	cin >> n >> d >> l;
	SET(M, -1);
	State t = dp(n, 0);
	if(t.v == 0) {
		printf("-1\n");
		return 0;
	}
	vector<int> r;
	for(int i = n, x = 0; i > 0; --i) {
		t = dp(i, x);
		r.push_back(t.x);
		x = t.x-t.y;
	}
	reverse(ALL(r));
	
	for(int i = 0; i < r.size(); ++i) {
		if(i > 0)
			printf(" ");
		printf("%d", r[i]);
	}
	printf("\n");
	return 0;
}
