// In the name of Allah, Most Gracious, Most Merciful

// Neighbor House (II)
// dp
// AC (402)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

int H[1005];
int M[1005][2];

int ans(int n, int i, int x, int l) {
	if(l >= n-1)
		return 0;
	int &r = M[i][x];
	if(r == -1) {
		r = 0;
		if(x == 0)
			r = max(r, ans(n, (i+1)%n, 1, l+1)+H[i%n]);
		r = max(r, ans(n, (i+1)%n, 0, l+1));
	}
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &H[i]);
		int r = 0;
		for(int i = 0; i < n; ++i) {
			SET(M);
			r = max(r, ans(n, (i+1)%n, 1, 1)+H[i]);
		}
		printf("Case %d: %d\n", no++, r);
	}
	return 0;
}
