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

template<class T, int N>
class Segtreesum {
	struct Data {
		T x;
		T f;
		
		Data() : x(0), f(false) { }
		Data(T x_) : x(x_), f(false) {}
	};
	
	Data merge(const Data &x, const Data &y) const {
		return Data(max(x.x, y.x));
	}
	
	void split(int n, int l, int h) {
		if(v[n].f) {
			v[n].x += v[n].f/(h-l);
			int m = (l+h+1)/2;
			v[2*n].f += v[n].f/(h-l)*(m-l);
			v[2*n+1].f += v[n].f/(h-l)*(h-m);
			v[n].f = 0;
		}
	}
	
	Data v[4*N+2];
	
	void set(int i, int j, T x, int n, int l, int h) {
		split(n, l, h);
		if(j <= l || i >= h)
			return;
		if(l >= i && h <= j) {
			v[n].f += x*(h-l);
			split(n, l, h);
			return;
		}
		int m = (l+h+1)/2;
		set(i, j, x, 2*n, l, m);
		set(i, j, x, 2*n+1, m, h);
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
	Segtreesum() {
		clear();
	}
	
	void clear() {
		for(int i = 0; i < 4*N+2; ++i)
			v[i] = Data();
	}
	
	void set(int i, int j, T x) {
		set(i, j, x, 1, 0, N);
	}
	
	int query(int i, int j) {
		return query(i, j, 1, 0, N).x;
	}
};

struct Query {
	char C[4];
	int a, b;
};

vector<Query> Qs;
vector<int> Xs;
Segtreesum<vlong, 5000000> ST;

int main() {
	int N;
	scanf("%d", &N);
	while(N--) {
		Query q;
		scanf("%s %d %d", q.C, &q.a, &q.b);
		Qs.push_back(q);
		Xs.push_back(q.a-1);
		Xs.push_back(q.a);
		Xs.push_back(q.b);
		Xs.push_back(q.b+1);
	}
	
	sort(ALL(Xs));
	for(int i = 0; i < Qs.size(); ++i) {
		switch(Qs[i].C[0]) {
		case '+':
			ST.set(upper_bound(ALL(Xs), Qs[i].a)-Xs.begin(), upper_bound(ALL(Xs), Qs[i].b+1)-Xs.begin(), 1);
			break;
		case '?':
			printf("%lld\n", ST.query(upper_bound(ALL(Xs), Qs[i].a)-Xs.begin(), upper_bound(ALL(Xs), Qs[i].b+1)-Xs.begin()));
			break;
		}
	}
	return 0;
}
