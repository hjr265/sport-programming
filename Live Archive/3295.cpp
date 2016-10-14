// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/3295
// Counting Triangles
// combinatorics
// 
// 
// AC (2011-10-21 07:00:12)

#include <cstdio>

typedef long long vlong;

vlong gcd(vlong a, vlong b) {
	return b == 0 ? a : gcd(b, a%b);
}

vlong count(vlong R, vlong C) {
	vlong z = 0;
	for(vlong i = 1; i <= R; ++i) {
		for(vlong j = 1; j <= C; ++j)
			z += ((R+1-i)*(C+1-j))*(4*(i-1)*(j-1)+2*((j-1)+(i-1)+((i+1)*(j+1)-4-(gcd(i, j)-1)))+4);
	}
	return z;
}

int main() {
	int no = 1;
	vlong R, C;
	while(scanf("%lld %lld", &R, &C) == 2 && (R != 0 || C != 0))
		printf("Case %d: %lld\n", no++, count(R, C));
	return 0;
}
