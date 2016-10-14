// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1096
// nth Term
// matrices
// 
// 
// AC (2011-10-25 00:28:35)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

const int mod = 10007LL;

template<int d>
class Matrix {
public:
	int v[d][d];
	
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
	
	Matrix<d> modpow(int p, int m) {
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
	
	Matrix<d> mod(int m) {
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
		int n, a, b, c;
		scanf("%d %d %d %d", &n, &a, &b, &c);
		Matrix<4> X;
		X.v[0][1] = 1;
		X.v[1][2] = 1;
		X.v[2][0] = b;
		X.v[2][2] = a;
		X.v[2][3] = c;
		X.v[3][3] = 1;
		Matrix<4> Y;
		Y.v[3][0] = 1;
		printf("Case %d: %d\n", no++, X.modpow(n, mod).mul(Y).v[0][0]%mod);
	}
	return 0;
}
