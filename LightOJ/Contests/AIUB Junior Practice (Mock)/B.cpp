// In the name of Allah, Most Gracious, Most Merciful

// LightOJ
// AIUB Junior Practice (Mock)
// B
// Come On Let's Tree
// implementation
// AC (1159)

#include <cstdio>

int A[100005];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &A[i]);
		for(int i = 2; i <= n; ++i)
			A[i] ^= A[i-1];
		int q;
		scanf("%d", &q);
		printf("Case %d:\n", no++);
		while(q--) {
			int u, v;
			scanf("%d %d", &u, &v);
			printf("%d\n", A[v]^A[u-1]);
		}
	}
	return 0;
}
