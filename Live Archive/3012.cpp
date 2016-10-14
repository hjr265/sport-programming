// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/3012
// All Integer Average
// implementation
// 
// 
// AC (2011-10-02 09:33:22)

#include <cmath>
#include <cstdio>
#include <cstdlib>

typedef long long vlong;

vlong gcd(vlong a, vlong b) {
	return b == 0 ? a : gcd(b, a%b);
}

struct Fraction {
	vlong n, d;
	
	Fraction(vlong n_, vlong d_) : n(n_), d(d_) {
		vlong g = gcd(abs(n), abs(d));
		n /= g, d /= g;
	}
	
	void print() {
		if(n%d == 0) {
			if(n < 0)
				printf("- ");
			printf("%d\n", abs(n)/d);
		} else if(n/d == 0) {
			int s = n/abs(n), w = log(d)/log(10)+1;
			char b[100];
			sprintf(b, "%s%%%dd\n", s == -1 ? "  " : "", w);
			printf(b, abs(n));
			if(s == -1)
				printf("- ");
			for(int i = 0; i < w; ++i)
				printf("-");
			printf("\n");
			sprintf(b, "%s%%%dd\n", s == -1 ? "  " : "", w);
			printf(b, d);
		} else {
			int s = n/abs(n), w = log(d)/log(10)+1, p = abs(n)/d, l = log(p)/log(10)+1;
			char b[100];
			sprintf(b, "%s%%%dd\n", s == -1 ? "  " : "", w+l);
			printf(b, abs(n) % d);
			if(s == -1)
				printf("- ");
			printf("%d", p);
			for(int i = 0; i < w; ++i)
				printf("-");
			printf("\n");
			sprintf(b, "%s%%%dd\n", s == -1 ? "  " : "", w+l);
			printf(b, d);
		}	
	}
};

int main() {
	vlong n, no = 1;
	while(scanf("%lld", &n) == 1 && n != 0) {
		vlong s = 0;
		for(vlong i = 0, x; i < n; ++i, s += x)
			scanf("%lld", &x);
		printf("Case %d:\n", no++);
		Fraction(s, n).print();
	}
	return 0;
}
