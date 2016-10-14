// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1019
// Brush (V)
// shortest paths
// 
// 
// AC (2011-07-29 11:28:03)

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long vlong;

vlong E[105][105];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N, M;
		scanf("%d %d", &N, &M);
		for(int i = 1; i <= N; ++i) {
			for(int j = 1; j <= N; ++j)
				E[i][j] = 1234567890;
		}
		while(M--) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			E[u][v] = E[v][u] = min(E[u][v], (vlong)w);
		}
		for(int k = 1; k <= N; ++k) {
			for(int i = 1; i <= N; ++i) {
				for(int j = 1; j <= N; ++j)
					E[i][j] = min(E[i][j], E[i][k]+E[k][j]);
			}
		}
		printf("Case %d: ", no++);
		if(E[1][N] == 1234567890)
			printf("Impossible\n");
		else
			printf("%d\n", E[1][N]);
	}
	return 0;
}
