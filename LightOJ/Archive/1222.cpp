// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1222
// Gift Packing
// flows
// 
// 
// AC (2012-05-23 13:48:03)

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))
#define SLC(c, n) c, c+n

using namespace std;

struct Edge {
	int v, f, c, w;
	
	Edge(int v_, int f_, int c_, int w_) : v(v_), f(f_), c(c_), w(w_) {}
};

int G[52][52];
vector<Edge> E[105];
int P[105];
int M[105];
int D[105];

int bellmanford() {
	SET(P);
	P[0] = -2;
	M[0] = 1<<30;
	fill(SLC(D, 105), -(1<<30));
	D[0] = 0;
	bool f = true;
	for(int i = 0; i < 105-1 && f; ++i) {
		f = false;
		for(int u = 0; u < 105; ++u) {
			for(int j = 0; j < E[u].size(); ++j) {
				Edge e = E[u][j];
				if(e.c-e.f > 0 && (P[e.v] == -1 || D[e.v] < D[u]+e.w)) {
					P[e.v] = u;
					D[e.v] = D[u]+e.w;
					M[e.v] = min(M[u], e.c-e.f);
					f = true;
				}
			}
		}
	}
	return D[105-1] == -(1<<30) ? 0 : M[105-1];
}

int edmonskarp() {
	int f = 0, c = 0;
	while(1) {
		int m = bellmanford();
		if(m == 0)
			break;
		f = f+m;
		int v = 105-1;
		while(v != 0) {
			int u = P[v];
			for(int i = 0; i < E[u].size(); ++i) if(E[u][i].v == v) {
				E[u][i].f += m;
				c += m*E[u][i].w;
				break;
			}
			for(int i = 0; i < E[v].size(); ++i) if(E[v][i].v == u) {
				E[v][i].f -= m;
				break;
			}
			v = u;
		}
	}
	return c;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int u = 0; u < 105; ++u)
			E[u].clear();
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j)
				scanf("%d", &G[i][j]);
		}
		for(int i = 1; i <= n; ++i) {
			E[0].push_back(Edge(i, 0, 1, 0));
			E[i].push_back(Edge(0, 0, 0, 0));
			E[50+i].push_back(Edge(105-1, 0, 1, 0));
			E[105-1].push_back(Edge(0, 0, 0, 0));
			for(int j = 1; j <= n; ++j) {
				E[i].push_back(Edge(50+j, 0, 1, G[i][j]));
				E[50+j].push_back(Edge(i, 0, 0, -G[i][j]));
			}
		}
		printf("Case %d: %d\n", no++, edmonskarp());
	}
	return 0;
}
