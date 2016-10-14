// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/4494
// How Many Ones Needed?
// combinatorics, dp
// 
// 
// AC (2011-10-06 04:58:19)

#include <cstdio>

typedef long long vlong;

vlong f(vlong a, vlong p = 2) {
	if(a/(p/2) == 0)
		return 0;
	vlong r = f(a, p*2);
	r += (a/p)*(p/2);
	if((a%p) > (p/2))
		r += (a%p)-(p/2);
	return r;
}

int main() {
	int no = 1;
	vlong a, b;
	while(scanf("%lld %lld", &a, &b) == 2 && (a != 0 || b != 0)) {
		printf("Case %d: %lld\n", no++, f(b+1)-f(a));
	}
	return 0;
}
