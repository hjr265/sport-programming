#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

bool g[25][25];
int r[25];
int f[25];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		memset(g, 0, sizeof(g));
		memset(r, 0, sizeof(r));
		memset(f, -1, sizeof(f));
		int z = 0, t = n * m;
		vector<int> q;
		for(int i = 0; i < n; ++i)
			q.push_back(i);
		for(int b = 0; t; ++b, b %= m, ++z) {
			if(f[b] != -1) {
				if(r[f[b]] < m) {
					q.push_back(f[b]);
				}
				f[b] = -1;
				--t;
			}
			for(int i = 0, l = q.size(); i < l; ++i) {
				int x = q[i];
				if(!g[x][b]) {
					q.erase(q.begin() + i);
					g[x][b] = true;
					++r[x];
					f[b] = x;
					break;
				}
			}
		}
		printf("Case %d: %d\n", no++, z * 5);
	}
	return 0;
}
