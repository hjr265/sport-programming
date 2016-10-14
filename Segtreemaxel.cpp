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
	N = 100000,
	Q = 10000
};

int A[N+2];
Segtreemaxel<int, N+6, -10000> T;

int main() {
	srand(time(NULL));
	
	for(int i = 0; i < N; ++i)
		A[i] = rand()%1000;
	
	for(int i = 0; i < N; ++i)
		T.set(i, A[i]);
	
	bool OK = true;
	
	for(int q = 1; OK && q <= Q; ++q) {
		int c = rand()%2;
		
		int i = rand()%N,
			j = i+rand()%(N-i),
			x = rand()%1000,
			m;
		
		switch(c) {
		case 0:
			T.set(i, x);
			A[i] = x;
			break;
		case 1:
			int m = T.query(i, j);
			for(; OK && i < j; ++i) if(A[i] > A[m])
				OK = false;
			
			break;
		}
	}
	
	if(OK)
		printf("OK\n");
	return 0;
}
