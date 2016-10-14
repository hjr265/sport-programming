// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1154
// Penguins
// flows
// 
// 
// AC (2012-03-12 00:11:54)

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

enum {
	Nmax = 100+2
};

struct Floe {
	double x, y;
	int n, m;
	
	Floe(double x_, double y_, int n_, int m_) : x(x_), y(y_), n(n_), m(m_) {}
	
	double distsq(const Floe &r) {
		return (x-r.x)*(x-r.x)+(y-r.y)*(y-r.y);
	}
};

struct Edge {
	int v, f, c;
	
	Edge(int v_, int f_, int c_) : v(v_), f(f_), c(c_) {}
};

vector<Floe> V;
vector<Edge> E[Nmax*2];
int P[Nmax*2];
int M[Nmax*2];

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
				if(e.v == Nmax*2-1)
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
		int v = Nmax*2-1;
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

void build(int N, double D, int t) {
	for(int u = 0; u < Nmax*2; ++u)
		E[u].clear();
	for(int u = 1; u <= N; ++u) {
		for(int v = 1; v <= N; ++v) if(u != v && V[u].distsq(V[v]) <= D*D) {
			E[u+N].push_back(Edge(v, 0, 1<<30));
			E[v].push_back(Edge(u+N, 0, 0));
		}
		E[u].push_back(Edge(u+N, 0, V[u].m));
		E[u+N].push_back(Edge(u, 0, 0));
		E[0].push_back(Edge(u, 0, V[u].n));
		E[u].push_back(Edge(0, 0, 0));
	}
	E[t].push_back(Edge(Nmax*2-1, 0, 1<<30));
	E[Nmax*2-1].push_back(Edge(t, 0, 0));
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N;
		double D;
		scanf("%d %lf", &N, &D);
		V.clear();
		V.push_back(Floe(0, 0, 0, 0));
		int p = 0;
		for(int i = N; i; --i) {
			double x, y;
			int n, m;
			scanf("%lf %lf %d %d", &x, &y, &n, &m);
			V.push_back(Floe(x, y, n, m));
			p += n;
		}
		vector<int> r;
		for(int t = 1; t <= N; ++t) {
			build(N, D, t);
			if(edmonskarp() == p)
				r.push_back(t-1);
		}
		if(r.size() == 0)
			r.push_back(-1);
		printf("Case %d:", no++);
		for(int i = 0; i < r.size(); ++i)
			printf(" %d", r[i]);
		printf("\n");
	}
	return 0;
}
