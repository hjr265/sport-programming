// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1140
// How Many Zeroes?
// *combinatorics, dp
// 
// 
// AC (2012-01-10 19:43:43)

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long vlong;

vlong zeros(vlong n) {
	if(n < 0)
		return 0;
	vlong r = 1;
	for(vlong i = 1; ; i *= 10) {
		vlong a = n/(i*10), b = (n/i)%10, c = n%i;
		if(a == 0)
			break;
		if(b == 0)
			r += (a-1)*i+c+1;
		else
			r += a*i;
	}
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong m, n;
		scanf("%lld %lld", &m, &n);
		printf("Case %d: %lld\n", no++, zeros(max(m, n))-zeros(min(m, n)-1));
	}
	return 0;
}
