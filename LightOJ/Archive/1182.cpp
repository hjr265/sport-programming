// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1182
// Parity
// implementation
// 
// 
// AC (2011-07-27 08:19:30)

#include <cstdio>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int z = 0;
		for(int i = 0; i < 31; ++i) if(n&(1<<i))
			z += 1;
		printf("Case %d: %s\n", no++, z%2 ? "odd" : "even");
	}
	return 0;
}
