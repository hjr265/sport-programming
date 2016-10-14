// In the name of Allah, Most Gracious, Most Merciful

// Segment Tree Maximum Element
// data structures, trees

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>

#define SET(c, v) memset(c, v, sizeof(c))

using namespace std;

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
		return query(i, j, 1, 0, N).v;
	}
};

enum {
	Nmax = 100000,
	Q = 10000
};

int A[Nmax+2];
Segtreemaxel<int, Nmax+6, -10000000> W;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		W.clear();	
	
		int N, q;
		scanf("%d %d", &N, &q);
		
		for(int i = 1; i <= N; ++i) {
			scanf("%d", &A[i]);
			A[i] *= -1;
			W.set(i, A[i]);
		}
		
		printf("Case %d:\n", no++);
		while(q--) {
			int I, J;
			scanf("%d %d", &I, &J);
			
			int m = W.query(I, J+1);
			printf("%d\n", -A[m]);
		}
	}
	return 0;
}
