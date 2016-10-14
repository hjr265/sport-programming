// In the name of Allah, Most Gracious, Most Merciful

// Timus/1877
// Bicycle Codes
// implementation
// 
// 
// AC (23:34:49 28 Apr 2012)

#include <cstdio>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf(a%2 == 0 || b%2 == 1 ? "yes\n" : "no\n");
	return 0;
}
