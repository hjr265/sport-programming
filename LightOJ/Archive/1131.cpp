// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1131
// Just Two Functions
// matrices
// 
// 
// AC (2011-10-29 20:49:31)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

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
		vlong a1, b1, c1, a2, b2, c2, f0, f1, f2, g0, g1, g2, M;
		scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &a1, &b1, &c1, &a2, &b2, &c2, &f0, &f1, &f2, &g0, &g1, &g2, &M);
		Matrix<6> X;
		X.v[0][0] = a1;
		X.v[0][1] = b1;
		X.v[0][5] = c1;
		X.v[1][0] = 1;
		X.v[2][1] = 1;
		X.v[3][2] = c2;
		X.v[3][3] = a2;
		X.v[3][4] = b2;
		X.v[4][3] = 1;
		X.v[5][4] = 1;
		Matrix<6> Y;
		Y.v[0][0] = f2;
		Y.v[1][0] = f1;
		Y.v[2][0] = f0;
		Y.v[3][0] = g2;
		Y.v[4][0] = g1;
		Y.v[5][0] = g0;
		Y = Y.mod(M);
		int q;
		scanf("%d", &q);
		printf("Case %d:\n", no++);
		while(q--) {
			vlong n;
			scanf("%lld", &n);
			Matrix<6> Z = X.modpow(n, M).mul(Y);
			printf("%lld %lld\n", Z.v[2][0]%M, Z.v[5][0]%M);
		}
	}
	return 0;
}
