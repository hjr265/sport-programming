// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1065
// Number Sequence
// matrices
// 
// 
// AC (2011-10-25 00:12:13)

#include <cmath>
#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

typedef long long vlong;

template<int d>
class Matrix {
public:
	vlong v[d][d];

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

	Matrix<d> modpow(vlong p, vlong m) {
		Matrix<d> r, b = *this;
		for(int i = 0; i < d; ++i)
			r.v[i][i] = 1;
		for(; p; p /= 2) {
			b = b.mod(m);
			if(p%2)
				r = r.mul(b).mod(m);
			b = b.mul(b);
		}
		return r;
	}

	Matrix<d> mod(vlong m) {
		Matrix<d> r;
		for(int i = 0; i < d; ++i) {
			for(int j = 0; j < d; ++j)
				r.v[i][j] = v[i][j]%m;
		}
		return r;
	}
};

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong a, b, n, m;
		scanf("%lld %lld %lld %lld", &a, &b, &n, &m);
		vlong mod = (vlong)pow(10, m);
		Matrix<2> X;
		X.v[0][0] = 1;
		X.v[0][1] = 1;
		X.v[1][0] = 1;
		X.v[1][1] = 0;
		Matrix<2> Y;
		Y.v[0][0] = b;
		Y.v[1][0] = a;
		printf("Case %d: %lld\n", no++, X.modpow(n, mod).mul(Y).v[1][0]%mod);
	}
	return 0;
}
