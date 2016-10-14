// In the name of Allah, Most Gracious, Most Merciful

// SPOJ/NSTEPS
// Number Steps
// math
// 
// 
// AC (2012-01-31 10:44:13)

#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);
	while(N--) {
		int x, y;
		scanf("%d %d", &x, &y);
		if(x == y || x == y+2)
			printf("%d\n", x+y-x%2);
		else
			printf("No Number\n");
	}
	return 0;
}
