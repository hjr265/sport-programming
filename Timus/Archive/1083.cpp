// In the name of Allah, Most Gracious, Most Merciful

// Timus/1083
// Factorials!!!
// implementation
// 
// 
// AC (18:07:17 28 Apr 2012)

#include <cstdio>
#include <cstring>

typedef long long vlong;

int main() {
	vlong n;
	char s[25];
	scanf("%lld %s", &n, s);
	vlong k = strlen(s);
	vlong r = 1;
	for(int i = 0; ; ++i) {
		if(n%k != 0 && n-i*k < n%k || n%k == 0 && n-i*k == 0)
			break;
		r *= n-i*k;
	}
	printf("%lld\n", r);
	return 0;
}
