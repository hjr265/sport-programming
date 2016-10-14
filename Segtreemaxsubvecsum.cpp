// In the name of Allah, Most Gracious, Most Merciful

// Segment Tree Maximum Subvector Sum
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

template<class T, int N, T Tmin>
class Segtreemaxsubvecsum {
	struct Data {
		T p, s, t, v;
		
		Data() : p(Tmin), s(Tmin), t(Tmin), v(Tmin) { }
		Data(T x) : p(x), s(x), t(x), v(x) {}
	};
	
	Data merge(const Data &x, const Data &y) const {
		Data z;
		z.t = x.t+y.t;
		z.p = max(x.p, x.t+y.p);
		z.s = max(y.s, y.t+x.s);
		z.v = max(max(x.v, y.v), x.s+y.p);
		return z;
	}
	
	T a[N+2];
	Data v[4*N+2];
	
	void set(int i, int x, int n, int l, int h) {
		if(i < l || i >= h)
			return;
		if(l == h-1) {
			a[l] = x;
			v[n] = Data(x);
			return;
		}
		int m = (l+h+1)/2;
		set(i, x, 2*n, l, m);
		set(i, x, 2*n+1, m, h);
		v[n] = merge(v[2*n], v[2*n+1]);
	}
	
	Data query(int i, int j, int n, int l, int h) {
		if(j <= l || i >= h)
			return Data();
		if(l >= i && h <= j)
			return v[n];
		int m = (l+h+1)/2;
		return merge(query(i, j, 2*n, l, m), query(i, j, 2*n+1, m, h));
	}

public:
	Segtreemaxsubvecsum() {
		clear();
	}
	
	void clear() {
		for(int i = 0; i < N+2; ++i)
			a[i] = Tmin;
		for(int i = 0; i < 4*N+2; ++i)
			v[i] = Data();
	}
	
	void set(int i, int x) {
		set(i, x, 1, 0, N);
	}
	
	int query(int i, int j) {
		return query(i, j, 1, 0, N).v;
	}
};

int main() {
	
	return 0;
}
