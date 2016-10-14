// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1405
// The Great Escape
// flows
// 
// 
// AC (2012-02-27 20:53:52)

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

struct Edge {
	int v, f, c;
	
	Edge(int v_, int f_, int c_) : v(v_), f(f_), c(c_) {}
};

char G[102][102];
vector<Edge> E[21000];
int P[21000];
int M[21000];

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
				if(e.v == 21000-1)
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
		int v = 21000-1;
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
		int M, N;
		scanf("%d %d", &M, &N);
		for(int u = 0; u < 21000; ++u)
			E[u].clear();
		for(int ui = 0; ui < M; ++ui) {
			scanf("%s", G[ui]);
			for(int uj = 0; uj < N; ++uj) {
				if(G[ui][uj] == '*') {
					E[0].push_back(Edge(ui*N+uj+1, 0, 1));
					E[ui*N+uj+1].push_back(Edge(0, 0, 0));
				}
				if(ui == 0 || ui == M-1 || uj == 0 || uj == N-1) {
					E[M*N+3+ui*N+uj+1].push_back(Edge(21000-1, 0, 1));
					E[21000-1].push_back(Edge(M*N+3+ui*N+uj+1, 0, 0));
				}
				E[ui*N+uj+1].push_back(Edge(M*N+3+ui*N+uj+1, 0, 1));
				E[M*N+3+ui*N+uj+1].push_back(Edge(ui*N+uj+1, 0, 0));
				const int x[][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
				for(int l = 0; l < 4; ++l) {
					int vi = ui+x[l][0], vj = uj+x[l][1];
					if(vi >= 0 && vi < M && vj >= 0 && vj < N) {
						E[M*N+3+ui*N+uj+1].push_back(Edge(vi*N+vj+1, 0, 1));
						E[vi*N+vj+1].push_back(Edge(M*N+3+ui*N+uj+1, 0, 0));
					}
				}
			}
		}
		printf("Case %d: %s\n", no++, edmonskarp() == E[0].size() ? "yes" : "no");
	}
	return 0;
}
