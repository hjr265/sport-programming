// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1010
// Knights in Chessboard
// graph matchings, *math
// 
// 
// AC (2012-01-26 20:55:38)

#include <cstdio>
#include <algorithm>

using namespace std;

int ans(int m, int n) {
	if(m > n)
		return ans(n, m);
	switch(m) {
	case 1:
		return n;
	case 2:
		return ((n+2)/4)*2*2;
	default:
		return (m*n+1)/2;
	}
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int m, n;
		scanf("%d %d", &m, &n);
		printf("Case %d: %d\n", no++, max(ans(m, n), m*n-ans(m, n)));
	}
	return 0;
}
