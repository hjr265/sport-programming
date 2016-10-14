// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/3288
// Harmonic Mean
// implementation
// 
// 
// AC (2011-10-02 14:07:25)

#include <cstdio>

typedef long long vlong;

vlong gcd(vlong a, vlong b) {
	return b == 0 ? a : gcd(b, a%b);
}

vlong lcm(vlong a, vlong b) {
	return (a/gcd(a, b))*b;
}

struct Fraction {
	vlong n, d;
	
	Fraction(vlong n_, vlong d_) : n(n_), d(d_) {
		vlong g = gcd(n, d);
		n /= g, d /= g;
	}
	
	Fraction operator+(Fraction b) {
		vlong l = lcm(d, b.d);
		return Fraction((l/d)*n+(l/b.d)*b.n, l);
	}
	
	Fraction operator*(Fraction b) {
		return Fraction(n*b.n, d*b.d);
	}
	
	Fraction operator/(Fraction b) {
		return Fraction(n*b.d, d*b.n);
	}
};

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		Fraction f(0, 1);
		for(int i = 0; i < N; ++i) {
			vlong a;
			scanf("%lld", &a);
			f = f+Fraction(1, a);
		}
		f = Fraction(N, 1)/f;
		printf("Case %d: %lld/%lld\n", no++, f.n, f.d);
	}
	return 0;
}
