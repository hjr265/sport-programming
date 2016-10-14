// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1008
// Fibsieve's Fantabulous Birthday
// math
// 
// 
// AC (2011-08-09 22:11:32)

#include <cmath>
#include <cstdio>

using namespace std;

typedef long long vlong;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong N;
		scanf("%lld", &N);
		vlong x = (vlong)sqrt(N-1)+1, y = x, z = x*(x-1)+1;
		if(x%2 == 1) {
			if(N > z)
				x -= N-z;
			else if(N < z)
				y -= z-N;
		} else {
			if(N > z)
				y -= N-z;
			else if(N < z)
				x -= z-N;
		}
		printf("Case %d: %lld %lld\n", no++, x, y);
	}
	return 0;
}
