// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1141
// Number Transformation
// dfs and similar
// 
// 
// AC (2011-09-10 17:26:17)

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define SET(d) memset(d, -1, sizeof(d))

using namespace std;

vector<int> f[1005];

int fsieve(int n, vector<int> f[]) {
	for(int i = 2; i < 1005; ++i) if(f[i].size() == 0) {
		for(int j = 2 * i; j < 1005; j += i)
			f[j].push_back(i);
	}
}

int main() {
	fsieve(1005, f);
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int s, t;
		scanf("%d %d", &s, &t);
		int d[1005];
		SET(d);
		queue<int> q;
		d[s] = 0;
		q.push(s);
		while(!q.empty() && d[t] == -1) {
			int u = q.front();
			q.pop();
			for(int i = 0, n = f[u].size(); i < n; ++i) {
				int v = u + f[u][i];
				if(v < 1005 && d[v] == -1) {
					d[v] = d[u] + 1;
					if(v == t)
						break;
					q.push(v);
				}
			}
		}
		printf("Case %d: %d\n", no++, d[t]);
	}
	return 0;
}
