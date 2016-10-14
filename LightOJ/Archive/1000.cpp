// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1000
// Greetings from LightOJ
// implementation
// 
// 
// AC (2011-07-26 21:59:12)

#include <cstdio>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("Case %d: %d\n", no++, a+b);
	}
	return 0;
}
