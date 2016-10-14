// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1077
// How Many Points?
// number theory
// 
// 
// AC (2011-08-04 10:57:13)

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long vlong;

vlong gcd(vlong a, vlong b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong Ax, Ay, Bx, By;
		scanf("%lld %lld %lld %lld", &Ax, &Ay, &Bx, &By);
		printf("Case %d: %lld\n", no++, gcd(abs(Bx-Ax), abs(By-Ay))+1);
	}
	return 0;
}
