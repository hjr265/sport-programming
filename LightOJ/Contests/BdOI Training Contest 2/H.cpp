// In the name of Allah, Most Gracious, Most Merciful

// A Dangerous Maze
// probability
// AC (382)

#include <cstdio>

typedef long long vlong;

template<class T> T gcd(T a, T b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		vlong a = 0, b = 0;
		for(int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			if(x < 0)
				a -= x, ++b;
			else
				a += x;
		}
		printf("Case %d: ", no++);
		if(b == n) {
			printf("inf\n");
		} else {
			vlong g = gcd(a, n-b);
			printf("%lld/%lld\n", a/g, (n-b)/g);
		}
	}
	return 0;
}
