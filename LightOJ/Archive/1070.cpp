// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1070
// Algebraic Problem
// matrices
// 
// 
// AC (2012-01-31 19:29:33)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

typedef unsigned long long uvlong;

template<int d>
class Matrix {
public:
	uvlong v[d][d];
	
	Matrix() {
		CLR(v);
	}
	
	Matrix<d> mul(const Matrix<d> &b) {
		Matrix<d> r;
		for(int k = 0; k < d; ++k) {
			for(int i = 0; i < d; ++i) {
				for(int j = 0; j < d; ++j)
					r.v[i][j] += v[i][k]*b.v[k][j];
			}
		}
		return r;
	}
	
	Matrix<d> pow(uvlong p) {
		Matrix<d> r, b = *this;
		for(int i = 0; i < d; ++i)
			r.v[i][i] = 1;
		for(; p; p /= 2) {
			if(p%2)
				r = r.mul(b);
			b = b.mul(b);
		}
		return r;
	}
};

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		uvlong p, q, n;
		scanf("%llu %llu %llu", &p, &q, &n);
		Matrix<2> a;
		a.v[0][0] = p;
		a.v[0][1] = -q;
		a.v[1][0] = 1;
		a.v[1][1] = 0;
		a = a.pow(n);
		Matrix<2> b;
		b.v[0][0] = p;
		b.v[1][0] = 2;
		b = a.mul(b);
		printf("Case %d: %llu\n", no++, b.v[1][0]);
	}
	return 0;
}
