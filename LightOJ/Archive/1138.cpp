// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1138
// Trailing Zeroes (III)
// binary search, number theory
// 
// 
// AC (2011-11-11 18:16:47)

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long vlong;

int f(vlong N) {
	if(N < 0)
		return -1;
	vlong t = 0, f = 0;
	vlong x = N;
	while(x > 1)
		x /= 2, t += x;
	x = N;
	while(x > 1)
		x /= 5, f += x;
	return min(t, f);
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong Q;
		scanf("%lld", &Q);
		vlong l = 0, h = 1LL<<32, m = -1;
		while(l <= h) {
			if(m == (l+h)/2)
				break;
			m = (l+h)/2;
			if(f(m) >= Q)
				h = m+1;
			else
				l = m-1;
		}
		printf("Case %d: ", no++);
		for(vlong i = m-10; i < m+10; ++i) if(f(i) == Q) {
			printf("%lld\n", i);
			m = -1;
			break;
		}
		if(m == -1)
			continue;
		printf("impossible\n");
	}
	return 0;
}
