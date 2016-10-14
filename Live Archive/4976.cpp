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

template<class T, int N, T Tmin>
class Segtreemaxel {
	struct Data {
		T v;
		
		Data() : v(N) { }
		Data(T x) : v(x) {}
	};
	
	Data merge(const Data &x, const Data &y) const {
		if(a[x.v] < a[y.v])
			return Data(y.v);
		return Data(x.v);
	}
	
	T a[N+2];
	Data v[4*N+2];
	
	void set(int i, int x, int n, int l, int h) {
		if(i < l || i >= h)
			return;
		if(l == h-1) {
			a[l] = max(a[l], x);
			v[n] = Data(l);
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
	Segtreemaxel() {
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
		return a[query(i, j, 1, 0, N).v];
	}
};

int X[200005];
vector<int> Xv;
int L[200005], R[200005];
Segtreemaxel<int, 200005, 0> ST;

int main() {
	int Z;
	scanf("%d", &Z);
	while(Z--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &X[i]);
		
		Xv.clear();
		for(int i = 0; i < n; ++i)
			Xv.push_back(X[i]);
		sort(ALL(Xv));
		for(int i = 0; i < n; ++i)
			X[i] = upper_bound(ALL(Xv), X[i])-Xv.begin();
		
		SET(L, 0);
		SET(R, 0);
		for(int i = 0; i < n; ++i) {
			if(i > 0 && X[i] > X[i-1])
				L[i] = L[i-1]+1;
			else
				L[i] = 1;
		}
		for(int i = n-1; i >= 0; --i) {
			if(i < n-1 && X[i] < X[i+1])
				R[i] = R[i+1]+1;
			else
				R[i] = 1;
		}
		
		int r = 0;
		ST.clear();
		for(int i = 0; i < n; ++i) {
			r = max(r, ST.query(0, X[i])+R[i]);
			ST.set(X[i], L[i]);
		}
		printf("%d\n", r);
	}
	return 0;
}
