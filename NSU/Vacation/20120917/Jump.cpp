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

template<int n>
class Bint {
	int v[n];
	
public:
	Bint() {
		SET(v, 0);
	}
	
	Bint(int x) {
		SET(v, 0);
		for(int i = 0; x; ++i, x /= 10)
			v[i] = x%10;
	}
	
	Bint<n> add(const Bint<n> &b) const {
		Bint<n> r;
		for(int i = 0, e = 0; i < n; ++i)
			r.v[i] = v[i]+b.v[i]+e, e = r.v[i]/10, r.v[i] %= 10;
		return r;
	}
	
	void print() {
		for(int i = n-1; i >= 0; --i) if(v[i] != 0 || i == 0) {
			for(int j = i; j >= 0; --j)
				printf("%d", v[j]);
			printf("\n");
			break;
		}
			
	}
};

struct State {
	Bint<102> v;
	bool t;
	
	State() {}
	State(int v_) : v(v_) {}
};

int n;
int G[102][102];

State D[102][102];

State dp(int i, int j) {
	if(i == n-1 && j == n-1)
		return State(1);
	State &r = D[i][j];
	if(!r.t) {
		r.v = Bint<102>();
		
		if(G[i][j] != 0) {
			
			if(i+G[i][j] < n)
				r.v = r.v.add(dp(i+G[i][j], j).v);
			
			if(j+G[i][j] < n)
				r.v = r.v.add(dp(i, j+G[i][j]).v);
			
		}
		
		r.t = true;
	}
	return r;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j)
			scanf("%d", &G[i][j]);
	}
	
	SET(D, 0);
	State r = dp(0, 0);
	r.v.print();
	return 0;
}
