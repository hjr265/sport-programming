// In the name of Allah, Most Gracious, Most Merciful

// Fenwick Tree
// data structures, trees

#include <cstdio>
#include <cstring>

#define SET(c, v) memset(c, v, sizeof(c))

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

int main() {
	
	return 0;
}
