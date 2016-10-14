// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1042
// Secret Origins
// implementation
// 
// 
// AC (2012-05-17 12:43:44)

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long vlong;

vlong fn(vlong N) {
	vlong z = N;
	for(vlong i = 1; i <= N; i <<= 1) if((z & i) > 0 && (z & (i << 1)) == 0) {
		z ^= i | (i << 1);
		i >>= 1;
		int x = 0;
		for(; i > 0; i >>= 1) if((N & i) > 0)
			z ^= i, ++x;
		for(vlong j = 1; x; --x, j <<= 1)
			z ^= j;
		break;
	}
	if(z > N)
		return z;
	return 1<<28;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong N;
		scanf("%lld", &N);
		printf("Case %d: %lld\n", no++, fn(N));
	}
	return 0;
}
