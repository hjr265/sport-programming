// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1233
// Coin Change (III)
// dp
// 
// 
// AC (2012-05-10 21:01:45)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

int A[102], C[102];
bool D[100005];
int E[100005];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T-- > 0) {
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; ++i)
			scanf("%d", &A[i]);
		for(int i = 0; i < n; ++i)
			scanf("%d", &C[i]);
		CLR(D);
		D[0] = true;
		for(int i = 0; i < n; ++i) {
			CLR(E);
			for(int j = 0; j <= m; ++j) if(!D[j])
				E[j] = 1<<28;
			for(int j = 0; j <= m-A[i]; ++j) {
				int k = j+A[i];
				if(D[j] && !D[k] && E[j]+1 <= C[i]) {
					E[k] = E[j]+1;
					D[k] = true;
				}
			}
		}
		int r = 0;
		for(int i = 1; i <= m; ++i) if(D[i])
			++r;
		printf("Case %d: %d\n", no++, r);
	}
	return 0;
}
