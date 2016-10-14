// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1001
// Opposite Task
// implementation
// 
// 
// AC (2011-07-26 22:03:32)

#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		printf("%d %d\n", n/2, n-n/2);
	}
	return 0;
}
