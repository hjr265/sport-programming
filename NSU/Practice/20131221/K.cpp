// In the name of Allah, Most Gracious, Most Merciful

// Fenwick Tree
// data structures, trees

#include <cstdio>
#include <cstring>

#define SET(c, v) memset(c, v, sizeof(c))

typedef long long vlong;

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

Fwtree<int, 10000007> W;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		W.clear();
		
		int n;
		scanf("%d", &n);
		
		vlong r = 0;
		for(int i = 0; i < n; ++i) {
			int a;
			scanf("%d", &a);
			
			r += W.sum(10000002) - W.sum(a+1);
			W.add(a+1, 1);
		}
		
		printf("%lld\n", r);
	}
	return 0;
}
