// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1135
// Count the Multiples of 3
// data structures, trees
// 
// 
// AC (2012-11-08 15:20:02)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define SET(c, v) memset(c, v, sizeof(c))

using namespace std;

template<int N>
class Segtreethree {
	struct Data {
		int x, y, z, f;
		
		Data() : x(0), y(0), z(0), f(0) { }
		Data(int x_, int y_, int z_) : x(x_), y(y_), z(z_), f(0) {}
	};
	
	static void merge(Data &r, const Data &x, const Data &y) {
		r.x = x.x+y.x;
		r.y = x.y+y.y;
		r.z = x.z+y.z;
	}
	
	void split(int n, int l, int h) {
		if(v[n].f) {
			v[n].f %= 3;
			while(v[n].f) {
				--v[n].f;
				swap(v[n].y, v[n].z);
				v[n].y = h-l-v[n].y-v[n].z;
				v[n].x = v[n].y+v[n].z;
				if(2*n < 4*N) {
					++v[2*n].f;
					++v[2*n+1].f;
				}
			}
		}
	}
	
	Data v[4*N+2];
	
	void set(int i, int j, int n, int l, int h) {
		split(n, l, h);
		if(j <= l || i >= h)
			return;
		if(l >= i && h <= j) {
			++v[n].f;
			split(n, l, h);
			return;
		}
		int m = (l+h+1)/2;
		set(i, j, 2*n, l, m);
		set(i, j, 2*n+1, m, h);
		merge(v[n], v[2*n], v[2*n+1]);
	}
	
	int query(int i, int j, int n, int l, int h) {
		split(n, l, h);
		if(j <= l || i >= h)
			return 0;
		if(l >= i && h <= j)
			return v[n].x;
		int m = (l+h+1)/2;
		return query(i, j, 2*n, l, m)+query(i, j, 2*n+1, m, h);
	}

public:
	Segtreethree() {
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
		return j-i-query(i, j, 1, 0, N);
	}
};

Segtreethree<100005> STT;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		STT.clear();
		int N, Q;
		scanf("%d %d", &N, &Q);
		printf("Case %d:\n", no++);
		while(Q--) {
			int C, A, B;
			scanf("%d %d %d", &C, &A, &B);
			switch(C) {
			case 0:
				STT.set(A, B+1);
				break;
			case 1:
				printf("%d\n", STT.query(A, B+1));
				break;
			}
		}
	}
	return 0;
}
