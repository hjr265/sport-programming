// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1227
// Boiled Eggs
// implementation
// 
// 
// AC (2011-08-09 23:02:22)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, P, Q;
		scanf("%d %d %d", &n, &P, &Q);
		int z[Q+1];
		CLR(z);
		while(n--) {
			int x;
			scanf("%d", &x);
			for(int i = Q; i >= x; --i)
				z[i] = max(z[i], 1+z[i-x]);
		}
		printf("Case %d: %d\n", no++, min(z[Q], P));
	}
	return 0;
}
