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
	double v;
	bool t;
	
	State() {}
	State(double v_) : v(v_) {}
};

int N;
double V[2002];
State D[2002][1002];

State dp(int i, int k) {
	int j = N-(2*k-i)-1;
	if(i == j)
		return State(V[i]);
	if(i > j || j < 0 || i >= N)
		return State(0);
	State &r = D[i][k];
	if(!r.t) {
		r.v = ((dp(i+2, k+1).v+dp(i+1, k+1).v)*0.5+V[i])*0.5+((dp(i+1, k+1).v+dp(i, k+1).v)*0.5+V[j])*0.5;
		r.t = true;
	}
	return r;
}

int main() {
	double X = 1;
	for(int i = 0; i < 1002; ++i) {
		cout << X << endl;
		X /= 2;
	}
	return 0;
	
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
			scanf("%lf", &V[i]);
		
		SET(D, 0);
		printf("%0.3lf\n", dp(0, 0).v);
	}
	return 0;
}
