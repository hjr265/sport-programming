// In the name of Allah, Most Gracious, Most Merciful

// Least Common Ancestor
// data structures, trees

#include <cstdio>
#include <cstring>
#include <algorithm>

#define SET(c, v) memset(c, v, sizeof(c))
#define SLC(c, n) c, c+(n)

using namespace std;

template<int N>
class Lca {
	int V[N+2], Vi[N+2], Vl;
	int E[4*N+2], El;
	int H[N+2];
	
public:
	Lca() {
		clear();
	}
	
	void clear() {
		SET(V, -1);
		Vl = 0;
		fill(SLC(E, 4*N+2), 1<<28);
		El = 0;
		SET(H, -1);
	}
	
	void found(int u) {
		if(V[u] == -1)
			V[u] = Vl++, Vi[V[u]] = u;
		u = V[u];
		if(H[u] == -1)
			H[u] = El;
		E[2*N+(El++)] = u;
	}
	
	void build() {
		for(int i = 2*N-1; i; --i)
			E[i] = min(E[2*i], E[2*i+1]);
	}
	
	int ancestor(int u, int v) {
		int l = H[V[u]], h = H[V[v]];
		if(l > h)
			swap(l, h);
		int r = 1<<28;
		for(l += 2*N, h += 2*N+1; l < h; l /= 2, h /= 2) {
			if(l&1)
				r = min(r, E[l++]);
			if(h&1)
				r = min(r, E[--h]);
		}
		return Vi[r];
	}
};

int main() {
	
	return 0;
}
