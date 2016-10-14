// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1029
// Civil and Evil Engineer
// mst
// 
// 
// AC (2011-07-27 21:08:51)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define CLR(c) memset(c, 0, sizeof(c))
#define ALL(c) c.begin(), c.end()

using namespace std;

typedef long long vlong;

class Dsets {
	int p[102], r[102];
	
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
		int u, v, w;
		E.clear();
		while(scanf("%d %d %d", &u, &v, &w) == 3 && (u != 0 || v != 0 || w != 0))
			E.push_back(Edge(u, v, w));
		vlong Z = 0;
		sort(ALL(E));
		S = Dsets();
		for(int i = 0; i < E.size(); ++i) if(S.parent(E[i].u) != S.parent(E[i].v)) {
			Z += E[i].w;
			S.merge(E[i].u, E[i].v);
		}
		S = Dsets();
		for(int i = E.size()-1; i >= 0; --i) if(S.parent(E[i].u) != S.parent(E[i].v)) {
			Z += E[i].w;
			S.merge(E[i].u, E[i].v);
		}
		printf("Case %d: ", no++);
		if(Z%2 == 0)
			printf("%d", Z/2);
		else
			printf("%d/2", Z);
		printf("\n");
	}
	return 0;
}
