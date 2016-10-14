// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1034
// Hit the Light Switches
// dfs and similar
// 
// 
// AC (2012-02-28 16:14:39)

#include <cstdio>
#include <cstring>
#include <vector>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

enum {
	Nmax = 10000+2
};

int N;
vector<int> E[Nmax];
vector<int> O;
char C[Nmax];

void dfs1(int u) {
	C[u] = true;
	for(int i = 0; i < E[u].size(); ++i) {
		int v = E[u][i];
		if(!C[v])
			dfs1(v);
	}
	O.push_back(u);
}

void dfs2(int u) {
	C[u] = true;
	for(int i = 0; i < E[u].size(); ++i) {
		int v = E[u][i];
		if(!C[v])
			dfs2(v);
	}
}

int scc() {
	O.clear();
	CLR(C);
	for(int u = 1; u <= N; ++u) if(!C[u])
		dfs1(u);
	int r = 0;
	CLR(C);
	for(int i = O.size()-1; i >= 0; --i) {
		int u = O[i];
		if(!C[u]) {
			++r;
			dfs2(u);
		}
	}
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int M;
		scanf("%d %d", &N, &M);
		for(int i = 0; i < Nmax; ++i)
			E[i].clear();
		while(M--) {
			int a, b;
			scanf("%d %d", &a, &b);
			E[a].push_back(b);
		}
		printf("Case %d: %d\n", no++, scc());
	}
	return 0;
}
