// In the name of Allah, Most Gracious, Most Merciful

// SPOJ/BUGLIFE
// A Bug’s Life
// dfs and similar
// 
// 
// AC (2012-11-25 07:20:33)

#include <cstdio>
#include <cstring>
#include <vector>

#define SET(c, v) memset(c, v, sizeof(c))

using namespace std;

vector<int> E[2002];
int C[2002];

bool color(int u, int c) {
	if(C[u] != -1)
		return C[u] == c;
	C[u] = c;
	for(int i = 0; i < E[u].size(); ++i) if(!color(E[u][i], !c))
		return false;
	return true;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		for(int i = 0; i < 2002; ++i)
			E[i].clear();
		
		int N, M;
		scanf("%d %d", &N, &M);
		while(M--) {
			int u, v;
			scanf("%d %d", &u, &v);
			E[u].push_back(v);
			E[v].push_back(u);
		}
		
		SET(C, -1);
		bool f = true;
		for(int u = 1; u <= N; ++u) if(C[u] == -1 && !color(u, 0))
			f = false;
		printf("Scenario #%d:\n", no++);
		if(f)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
	}
	return 0;
}
