// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1357
// Corrupted Friendship
// dfs and similar
// 
// 
// AC (2012-05-23 11:55:44)

#include <cstdio>
#include <vector>

using namespace std;

typedef long long vlong;

int N;
vector<int> E[100005];
vlong z;

int dfs(int u, int l) {
	int r = 1;
	for(int i = 0; i < E[u].size(); ++i)
		r += dfs(E[u][i], l+1);
	z += N-(r+l);
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 0; i < 100005; ++i)
			E[i].clear();
		for(int i = 0; i < N-1; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			E[u].push_back(v);
		}
		z = 0;
		dfs(1, 0);
		printf("Case %d: %d %lld\n", no++, N-1, z/2);
	}
	return 0;
}
