// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1053
// Higher Math
// math
// 
// 
// AC (2011-07-26 23:32:43)

#include <cstdio>
#include <algorithm>

#define SLC(c, n) c, c+n

using namespace std;

typedef long long vlong;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong X[3];
		scanf("%lld %lld %lld", &X[0], &X[1], &X[2]);
		sort(SLC(X, 3));
		printf("Case %d: %s\n", no++, X[0]*X[0]+X[1]*X[1] == X[2]*X[2] ? "yes" : "no");
	}
	return 0;
}
