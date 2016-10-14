// In the name of Allah, Most Gracious, Most Merciful

// ??
// ??
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
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))
#define ALL(c) c.begin(), c.end()
#define SLC(c, n) c, c+n

using namespace std;

typedef unsigned int uint;
typedef long long vlong;
typedef unsigned long long uvlong;

const double inf = 1e20;
const double pi = acos(-1.0);

class Segtree {
	vlong s[100002*5], t[100002*5];
	
public:
	Segtree() {
		CLR(s);
		CLR(t);
	}
	
	void add(int i, int j, vlong v, int u = 1, int l = 1, int r = 
100002) {
		if(r < i || l > j)
			return;
		if(l >= i && r <= j) {
			s[u] += (vlong)(r-l+1)*v;
			t[u] += v;
		} else {
			int m = (l+r)/2;
			add(i, j, v, 2*u, l, m);
			add(i, j, v, 2*u+1, m+1, r);
			s[u] = s[2*u]+s[2*u+1]+t[u]*(vlong)(r-l+1);
		}
	}
	
	vlong sum(int i, int j, vlong c = 0, int u = 1, int l = 1, int r 
= 100002) {
		if(r < i || l > j)
			return 0;
		if(l >= i && r <= j) {
			return s[u]+(vlong)(r-l+1)*c;
		} else {
			int m = (l+r)/2;
			return sum(i, j, c+t[u], 2*u, l, m)+sum(i, j, 
c+t[u], 2*u+1, m+1, r);
		}
	}
};

Segtree r;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, q;
		scanf("%d %d", &n, &q);
		r = Segtree();
		printf("Case %d:\n", no++);
		while(q--) {
			int c, x, y, v;
			scanf("%d %d %d", &c, &x, &y);
			switch(c) {
			case 0:
				scanf("%d", &v);
				r.add(x+1, y+1, v);
				break;
			case 1:
				printf("%lld\n", r.sum(x+1, y+1));
				break;
			}
		}
	}
	return 0;
}
