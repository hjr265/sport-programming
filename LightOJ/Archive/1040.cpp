// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1040
// Donation
// mst
// 
// 
// AC (2011-07-27 21:27:42)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define CLR(c) memset(c, 0, sizeof(c))
#define ALL(c) c.begin(), c.end()

using namespace std;

typedef long long vlong;

class Dsets {
	int p[52], r[52];
	
public:
	Dsets() {
		for(int i = 0; i < 102; ++i)
			p[i] = i;
		CLR(r);
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

struct Edge {
	int u, v, w;
	
	Edge(int u_, int v_, int w_) : u(u_), v(v_), w(w_) {}
	
	bool operator<(const Edge &r) const {
		return w < r.w;
	}
};

vector<Edge> E;
Dsets S;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		vlong Z = 0;
		E.clear();
		for(int u = 0; u < n; ++u) {
			for(int v = 0; v < n; ++v) {
				int w;
				scanf("%d", &w);
				if(w > 0)
					E.push_back(Edge(u, v, w));
				Z += w;
			}
		}
		sort(ALL(E));
		S = Dsets();
		for(int i = 0; i < E.size(); ++i) if(S.parent(E[i].u) != S.parent(E[i].v)) {
			Z -= E[i].w;
			S.merge(E[i].u, E[i].v);
		}
		for(int u = 1; u < n; ++u) if(S.parent(0) != S.parent(u)) {
			Z = -1;
			break;
		}
		printf("Case %d: %lld\n", no++, Z);
	}
	return 0;
}
