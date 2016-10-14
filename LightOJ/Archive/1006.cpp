// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1006
// Hex-a-bonacci
// implementation
// 
// 
// AC (2011-07-26 22:22:27)

#include <cstdio>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))

typedef long long vlong;

vlong M[10005];

vlong fn(int n) {
	vlong &r = M[n];
	if(r == -1)
		r = fn(n-1)+fn(n-2)+fn(n-3)+fn(n-4)+fn(n-5)+fn(n-6);
	return r%10000007;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		SET(M);
		int n;
		scanf("%lld %lld %lld %lld %lld %lld %d", &M[0], &M[1], &M[2], &M[3], &M[4], &M[5], &n);
		printf("Case %d: %lld\n", no++, fn(n));
	}
}
