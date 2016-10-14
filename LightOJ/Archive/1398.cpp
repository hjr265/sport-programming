// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1398
// Winger Trial
// flows
// 
// 
// AC (2012-03-12 02:29:59)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

typedef long long vlong;

struct Defndr {
	vlong x, y;
	
	Defndr(vlong x_, vlong y_) : x(x_), y(y_) {}
	
	vlong distsq(const Defndr &r) const {
		return (x-r.x)*(x-r.x)+(y-r.y)*(y-r.y);
	}
};

struct Edge {
	int v, f, c;
	
	Edge(int v_, int f_, int c_) : v(v_), f(f_), c(c_) {}
};

vector<Defndr> V;
vector<Edge> E[205];
int P[205];
int M[205];

int bfs() {
	SET(P);
	P[0] = -2;
	M[0] = 1<<30;
	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < E[u].size(); ++i) {
			Edge e = E[u][i];
			if(e.c-e.f > 0 && P[e.v] == -1) {
				P[e.v] = u;
				M[e.v] = min(M[u], e.c-e.f);
				if(e.v == 205-1)
					return M[e.v];
				q.push(e.v);
			}
		}
	}
	return 0;
}

int edmonskarp() {
	int f = 0;
	while(1) {
		int m = bfs();
		if(m == 0)
			break;
		f = f+m;
		int v = 205-1;
		while(v != 0) {
			int u = P[v];
			for(int i = 0; i < E[u].size(); ++i) if(E[u][i].v == v) {
				E[u][i].f += m;
				break;
			}
			for(int i = 0; i < E[v].size(); ++i) if(E[v][i].v == u) {
				E[v][i].f -= m;
				break;
			}
			v = u;
		}
	}
	return f;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong L, W, d;
		int N;
		scanf("%lld %lld %d %lld", &L, &W, &N, &d);
		V.clear();
		V.push_back(Defndr(-1, -1));
		for(int i = 0; i < N; ++i) {
			vlong x, y;
			scanf("%lld %lld", &x, &y);
			V.push_back(Defndr(x, y));
		}
		for(int i = 0; i < 205; ++i)
			E[i].clear();
		for(int u = 1; u < V.size(); ++u) {
			E[u].push_back(Edge(u+N, 0, 1));
			E[u+N].push_back(Edge(u, 0, 0));
			for(int v = 1; v < V.size(); ++v) if(u != v && V[u].distsq(V[v]) <= (d*2)*(d*2)) {
				E[u+N].push_back(Edge(v, 0, 1));
				E[v].push_back(Edge(u+N, 0, 0));
			}
			if(W-V[u].y <= d) {
				E[0].push_back(Edge(u, 0, 1));
				E[u].push_back(Edge(0, 0, 0));
			}
			if(V[u].y <= d) {
				E[u+N].push_back(Edge(205-1, 0, 1));
				E[205-1].push_back(Edge(u+N, 0, 0));
			}
		}
		printf("Case %d: %d\n", no++, edmonskarp());
	}
	return 0;
}
