// In the name of Allah, Most Gracious, Most Merciful

// Timus/1787
// Turn for MEGA
// implementation
// 
// 
// AC (10:03:50 29 Apr 2012)

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int k, n;
	scanf("%d %d", &k, &n);
	int q = 0;
	while(n--) {
		int a;
		scanf("%d", &a);
		q += a;
		q -= k;
		if(q < 0)
			q = 0;
	}
	printf("%d\n", q);
	return 0;
}
