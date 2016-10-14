// In the name of Allah, Most Gracious, Most Merciful

// Lift
// math
// AC (49)

#include <cstdio>
#include <cstdlib>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int f, s;
		scanf("%d %d", &f, &s);
		printf("Case %d: %d\n", no++, abs(f-s)*4+3+5+3+f*4+3+5);
	}
	return 0;
}
