// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1417
// Forwarding Emails
// dfs and similar
// 
// 
// AC (2012-02-27 20:38:47)

#include <cstdio>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))

int E[50002];
int I[50002];
int M[50002];
int X[50002];
char C[50002];
int s;

void dfs2(int u, int e, int h) {
	M[u] = h;
	int v = E[u];
	if(u != e)
		dfs2(v, e, h);
}

int dfs1(int u) {
	C[u] = 1;
	X[u] = ++s;
	int v = E[u];
	if(C[v] == 0) {
		int h = dfs1(v)+1;
		if(M[v] == -1)
			M[v] = h;
	} else if(C[v] == 1) {
		dfs2(v, u, X[u]-X[v]+1);
	} else {
		if(M[v] == -1)
			M[v] = M[u]+1;
	}
	C[u] = 2;
	return M[v];
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		CLR(E);
		CLR(I);
		for(int i = 0; i < N; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			E[u] = v;
			++I[v];
		}
		SET(M);
		CLR(C);
		CLR(X);
		int z = 0, r;
		for(int i = 0; i < 2; ++i) {
			for(int u = 1; u <= N; ++u) if((I[u] == 0 || i == 1) && C[u] == 0) {
				s = 0;
				int h = dfs1(u);
				if(h > z)
					z = h, r = u;
			}
		}
		printf("Case %d: %d\n", no++, r);
	}
	return 0;
}
