// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1219
// Mafia
// greedy
// 
// 
// AC (2012-05-02 11:20:16)

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

vector<int> E[10002];
int M[10002];
bool C[10002];
int R;

int dfs(int u) {
	int t = M[u]-1;
	for(int i = 0; i < E[u].size(); ++i) {
		t += dfs(E[u][i]);
	}
	R += abs(t);
	return t;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < 10002; ++i)
			E[i].clear();
		CLR(M);
		CLR(C);
		for(int i = 0; i < n; ++i) {
			int u;
			scanf("%d", &u);
			int d;
			scanf("%d %d", &M[u], &d);
			for(int j = 0; j < d; ++j) {
				int v;
				scanf("%d", &v);
				E[u].push_back(v);
				C[v] = true;
			}
		}
		int s = 0;
		for(int u = 1; u <= n; ++u) if(!C[u]) {
			s = u;
			break;
		}
		R = 0;
		dfs(s);
		printf("Case %d: %d\n", no++, R);
	}
	return 0;
}
