// In the name of Allah, Most Gracious, Most Merciful

// Timus/1028
// Stars
// data structures, trees
// 
// 
// AC (09:16:26 16 Oct 2012)

#include <cstdio>
#include <cstring>

#define SET(c, v) memset(c, v, sizeof(c))

template<class T, int n>
class Fwtree {
	T v[n+5];
	
public:
	Fwtree() {
		clear();
	}
	
	void clear() {
		SET(v, 0);
	}
	
	void add(int i, T x) {
		++i;
		while(i < n+5)
			v[i] += x, i += i & -i;
	}
	
	T sum(int i) {
		++i;
		T r = 0;
		while(i > 0)
			r += v[i], i -= i & -i;
		return r;
	}
};

Fwtree<int, 32005> F;
int R[32005];

int main() {
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		int X, Y;
		scanf("%d %d", &X, &Y);
		F.add(X, 1);
		++R[F.sum(X)-1];
	}
	
	for(int i = 0; i < N; ++i)
		printf("%d\n", R[i]);
	return 0;
}
