// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1241
// Pinocchio
// implementation
// 
// 
// AC (2011-09-16 17:01:43)

#include <cstdio>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int t = 2, z = 0;
		while(n--) {
			int a;
			scanf("%d", &a);
			z += (a-t+4)/5;
			t = a;
		}
		printf("Case %d: %d\n", no++, z);
	}
	return 0;
}
