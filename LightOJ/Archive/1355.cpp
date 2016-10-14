// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1355
// Game of CS
// games
// 
// 
// AC (2012-01-29 22:32:28)

#include <cstdio>
#include <cstring>
#include <vector>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

vector<int> G[1002];
int W[1002][1002];
bool V[1002];

int nimber(int u) {
	V[u] = true;
	int r = 0;
	for(int i = 0; i < G[u].size(); ++i) if(!V[G[u][i]]) {
		if(W[u][G[u][i]] == 1) {
			r ^= 1+nimber(G[u][i]);
		} else {
			r ^= nimber(G[u][i]);
			r ^= W[u][G[u][i]]%2;
		}
	}
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int u = 0; u < 1002; ++u)
			G[u].clear();
		CLR(W);
		for(int i = 0; i < n-1; ++i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			G[u].push_back(v);
			G[v].push_back(u);
			W[u][v] = W[v][u] = w;
		}
		CLR(V);
		printf("Case %d: %s\n", no++, nimber(0) ? "Emily" : "Jolly");
	}
	return 0;
}
