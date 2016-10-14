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
class Fwtree {
	T t[N+2];
	
public:
	Fwtree() {
		clear();
	}
	
	void clear() {
		SET(t, 0);
	}
	
	void add(int i, T x) {
		++i;
		while(i < N+2)
			t[i] += x, i += i&-i;
	}
	
	T sum(int i) {
		++i;
		T r = 0;
		while(i)
			r += t[i], i -= i&-i;
		return r;
	}
};

Fwtree<int, 200005> T;
int a[200005];
vector<pair<int, int> > V;

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(SLC(a, n));
	
	for(int i = 0; i < q; ++i) {
		int l, r;
		scanf("%d %d", &l, &r);
		T.add(l, 1);
		T.add(r+1, -1);
	}
	
	for(int i = 1; i <= n; ++i) {
		V.push_back(pair<int, int>(T.sum(i), i));
	}
	sort(ALL(V));
	
	vlong R = 0;
	for(int i = V.size()-1; i >= 0; --i) {
		R += vlong(a[i]) * vlong(V[i].first);
	}
	
	cout << R << endl;
	return 0;
}
