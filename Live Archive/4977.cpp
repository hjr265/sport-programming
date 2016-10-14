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
		if(a[y.v] > a[x.v])
			return Data(y.v);
		return Data(x.v);
	}
	
	T a[N+2];
	Data v[4*N+2];
	
	void set(int i, int x, int n, int l, int h) {
		if(i < l || i >= h)
			return;
		if(l == h-1) {
			a[l] = x;
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
		int r = query(i, j, 1, 0, N).v;
		if(a[r] == 0)
			return -1;
		return r;
	}
};

int L[1000005];
int W[1000005];
Segtreemaxel<int, 1000005, 0> ST;

int main() {
	int Z;
	scanf("%d", &Z);
	while(Z--) {
		int n, m;
		scanf("%d %d", &n, &m);
		
		ST.clear();
		bool f = true;
		SET(L, 0);
		SET(W, -1);
		for(int i = 0; i < m; ++i) {
			int t;
			scanf("%d", &t);
			if(!f)
				continue;
			if(t == 0) {
				ST.set(i, 1);
				W[i] = 0;
			} else {
				int j = ST.query(L[t], i);
				if(j == -1) {
					f = false;
				} else {
					ST.set(j, 0);
					W[j] = t;
				}
				L[t] = i;
			}
		}
		
		if(f) {
			printf("YES\n");
			bool p = false;
			for(int i = 0; i < m; ++i) if(W[i] != -1) {
				if(p)
					printf(" ");
				p = true;
				printf("%d", W[i]);
			}
			printf("\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
