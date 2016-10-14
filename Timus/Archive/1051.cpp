// In the name of Allah, Most Gracious, Most Merciful

// Timus/1051
// Simple Game on a Grid
// games
// 
// 
// AC (12:22:53 30 May 2012)

#include <cstdio>

int ans(int m, int n) {
	if(m == 1)
		return (n+1)/2;
	if(m%3 == 0 || n%3 == 0)
		return 2;
	return 1;
}

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	printf("%d\n", ans(min(m, n), max(m, n)));
	return 0;
}
