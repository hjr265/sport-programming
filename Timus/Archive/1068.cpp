// In the name of Allah, Most Gracious, Most Merciful

// Timus/1068
// Sum
// implementation
// 
// 
// AC (13:31:50 28 Apr 2012)

#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);
	printf("%d\n", N > 0 ? (N*(N+1))/2 : -(N*(N-1))/2+1);
	return 0;
}
