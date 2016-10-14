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
		if(a[r] == 1)
			return r;
		return -1;
	}
};

struct Query {
	int i, B, E;
	int Z;
	
	bool operator<(const Query &r) const {
		return B < r.B;
	}
};

int M, Q;
int K[1000005];
int Ko[1000005];
vector<int> Kd;
vector<Query> Qs;
int R[1000005], Rk[1000005];
Segtreemaxel<int, 1000005, 0> ST;

int main() {
	while(scanf("%d %d", &M, &Q) == 2 && (M != 0 || Q != 0)) {
		Kd.clear();
		for(int i = 0; i < M; ++i) {
			scanf("%d", &Ko[i]);
			Kd.push_back(Ko[i]);
		}
		sort(ALL(Kd));
		for(int i = 0; i < M; ++i)
			K[i] = upper_bound(ALL(Kd), Ko[i])-Kd.begin();
		Qs.clear();
		for(int i = 0; i < Q; ++i) {
			Query q;
			scanf("%d %d", &q.B, &q.E);
			q.i = i;
			--q.B;
			--q.E;
			Qs.push_back(q);
		}
		sort(ALL(Qs));
		
		SET(Rk, -1);
		for(int i = M-1; i >= 0; --i)
			R[i] = Rk[K[i]], Rk[K[i]] = i;
		
		ST.clear();
		for(int i = M-1; i >= 0; --i)
			ST.set(i, Rk[K[i]] == i ? 0 : 1);
		
		for(int i = 0, l = 0; i < Q; ++i) {
			for(int j = l; j < Qs[i].B; ++j) {
				if(R[j] != -1)
					ST.set(R[j], 0);
			}
			l = Qs[i].B;
			Qs[i].Z = ST.query(l, Qs[i].E+1);
			swap(Qs[i].B, Qs[i].i);
		}
		sort(ALL(Qs));
		
		for(int i = 0; i < Q; ++i) {
			if(Qs[i].Z != -1)
				printf("%d\n", Ko[Qs[i].Z]);
			else
				printf("OK\n");
		}
		printf("\n");
	}
	return 0;
}
