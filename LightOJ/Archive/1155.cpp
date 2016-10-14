// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1155
// Power Transmission
// flows
// 
// 
// AC (2012-02-28 17:03:52)

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

enum {
	Nmax = 100+2
};

struct Edge {
	int v, f, c;
	
	Edge(int v_, int f_, int c_) : v(v_), f(f_), c(c_) {}
};

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

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		for(int u = 0; u < Nmax*2; ++u)
			E[u].clear();
		int N;
		scanf("%d", &N);
		for(int u = 1; u <= N; ++u) {
			int c;
			scanf("%d", &c);
			E[u].push_back(Edge(u+Nmax, 0, c));
			E[u+Nmax].push_back(Edge(u, 0, 0));
		}
		int M;
		scanf("%d", &M);
		for(int k = 0; k < M; ++k) {
			int i, j, C;
			scanf("%d %d %d", &i, &j, &C);
			E[i+Nmax].push_back(Edge(j, 0, C));
			E[j].push_back(Edge(i+Nmax, 0, 0));
		}
		int B, D;
		scanf("%d %d", &B, &D);
		while(B--) {
			int i;
			scanf("%d", &i);
			E[0].push_back(Edge(i, 0, 1<<28));
			E[i].push_back(Edge(0, 0, 0));
		}
		while(D--) {
			int i;
			scanf("%d", &i);
			E[i+Nmax].push_back(Edge(Nmax*2-1, 0, 1<<28));
			E[Nmax*2-1].push_back(Edge(i+Nmax, 0, 0));
		}
		printf("Case %d: %d\n", no++, edmonskarp());
	}
	return 0;
}
