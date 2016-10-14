// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1200
// Thief
// dp
// 
// 
// AC (2012-03-10 23:27:16)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

int p[102], c[102], w[102];
int d[10002];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, W;
		scanf("%d %d", &n, &W);
		for(int i = 0; i < n; ++i)
			scanf("%d %d %d", &p[i], &c[i], &w[i]);
		for(int i = 0; i < n; ++i)
			W -= w[i]*c[i];
		printf("Case %d: ", no++);
		if(W >= 0) {
			CLR(d);
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j <= W; ++j) if(j+w[i] <= W)
					d[j+w[i]] = max(d[j+w[i]], d[j]+p[i]);
			}
			printf("%d", d[W]);
		} else {
			printf("Impossible");
		}
		printf("\n");
	}
	return 0;
}
