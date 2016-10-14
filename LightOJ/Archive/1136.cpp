// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1136
// Division by 3
// math
// 
// 
// AC (2011-08-07 16:37:08)

#include <cstdio>

typedef long long vlong;

vlong fn(int A) {
	return A/3*2+(A%3 == 2 ? 1 : 0);
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong A, B;
		scanf("%lld %lld", &A, &B);
		printf("Case %d: %lld\n", no++, fn(B)-fn(A-1));
	}
	return 0;
}
