// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1262
// Diagonal Sum
// flows
// 
// 
// AC (2012-05-28 01:33:02)

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

struct Edge {
	int v, f, c;
	
	Edge(int v_, int f_, int c_) : v(v_), f(f_), c(c_) {}
};

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

int L[105], R[105];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int m, n;
		scanf("%d %d", &m, &n);
		for(int i = 0; i < 205; ++i)
			E[i].clear();
		CLR(L);
		CLR(R);
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j)
				++L[i+j+1], ++R[i+(n-j)];
		}
		for(int i = 1; i <= m+n-1; ++i) {
			int x;
			scanf("%d", &x);
			E[0].push_back(Edge(i, 0, x-L[i]));
			E[i].push_back(Edge(0, 0, 0));
		}
		for(int i = 1; i <= m+n-1; ++i) {
			int x;
			scanf("%d", &x);
			E[i+100].push_back(Edge(205-1, 0, x-R[i]));
			E[205-1].push_back(Edge(i+100, 0, 0));
		}
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				E[i+j+1].push_back(Edge(i+(n-j)+100, 0, 99));
				E[i+(n-j)+100].push_back(Edge(i+j+1, 0, 0));
			}
		}
		edmonskarp();
		printf("Case %d:\n", no++);
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				if(j != 0)
					printf(" ");
				for(int k = 0; k < E[i+j+1].size(); ++k) if(E[i+j+1][k].v == i+(n-j)+100) {
					printf("%d", E[i+j+1][k].f+1);
					break;
				}
			}
			printf("\n");
		}
	}
	return 0;
}
