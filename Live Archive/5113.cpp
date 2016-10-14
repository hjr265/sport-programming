// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/5113
// Cookie Piles
// math
// 
// 
// AC (2011-09-19 13:21:57)

#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int N, A, D;
		scanf("%d %d %d", &N, &A, &D);
		printf("%d\n", (N*(2*A+(N-1)*D))/2);
	}
	return 0;
}
