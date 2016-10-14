// In the name of Allah, Most Gracious, Most Merciful

// Segment Tree Flips
// data structures, trees

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

template<int N>
class Segtreeflips {
	struct Data {
		int x;
		bool f;
		
		Data() : x(0), f(false) { }
		Data(int x_) : x(x_), f(false) {}
	};
	
	Data merge(const Data &x, const Data &y) const {
		return Data(x.x+y.x);
	}
	
	void split(int n, int l, int h) {
		if(v[n].f) {
			v[n].x = h-l-v[n].x;
			v[2*n].f = !v[2*n].f;
			v[2*n+1].f = !v[2*n+1].f;
			v[n].f = false;
		}
	}
	
	Data v[4*N+2];
	
	void set(int i, int j, int n, int l, int h) {
		split(n, l, h);
		if(j <= l || i >= h)
			return;
		if(l >= i && h <= j) {
			v[n].f = !v[n].f;
			split(n, l, h);
			return;
		}
		int m = (l+h+1)/2;
		set(i, j, 2*n, l, m);
		set(i, j, 2*n+1, m, h);
		v[n] = merge(v[2*n], v[2*n+1]);
	}
	
	Data query(int i, int j, int n, int l, int h) {
		split(n, l, h);
		if(j <= l || i >= h)
			return Data();
		if(l >= i && h <= j)
			return v[n];
		int m = (l+h+1)/2;
		return merge(query(i, j, 2*n, l, m), query(i, j, 2*n+1, m, h));
	}

public:
	Segtreeflips() {
		clear();
	}
	
	void clear() {
		for(int i = 0; i < 4*N+2; ++i)
			v[i] = Data();
	}
	
	void set(int i, int j) {
		set(i, j, 1, 0, N);
	}
	
	int query(int i, int j) {
		return query(i, j, 1, 0, N).x;
	}
};

int main() {
	
	return 0;
}
