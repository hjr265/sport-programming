// In the name of Allah, Most Gracious, Most Merciful

// Disjoint Sets
// data structures

#include <cstdio>
#include <cstring>

#define SET(c, v) memset(c, v, sizeof(c))

template<int N>
class Dsets {
	int p[N], r[N];
	
public:
	Dsets() {
		clear();
	}
	
	void clear() {
		for(int i = 0; i < N; ++i)
			p[i] = i;
		SET(r, 0);
	}
	
	int parent(int a) {
		if(p[a] != a)
			p[a] = parent(p[a]);
		return p[a];
	}
	
	void merge(int a, int b) {
		a = parent(a);
		b = parent(b);
		if(r[a] > r[b])
			p[b] = a;
		else
			p[a] = b;
		if(r[a] == r[b])
			++r[b];
	}
};

int main() {
	
	return 0;
}
