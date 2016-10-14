// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1244
// Tiles
// matrices
// 
// 
// AC (2012-05-13 23:44:16)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

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
	
	Matrix<d> pow(int p) {
		Matrix<d> r, b = *this;
		for(int i = 0; i < d; ++i)
			r.v[i][i] = 1;
		for(; p; p /= 2) {
			b = b.mod(10007);
			if(p%2)
				r = r.mul(b).mod(10007);
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
		int N;
		scanf("%d", &N);
		Matrix<3> a;
		a.v[0][0] = 1;
		a.v[0][1] = 1;
		a.v[0][2] = 2;
		a.v[1][0] = 1;
		a.v[2][1] = 1;
		a.v[2][2] = 1;
		a = a.pow(N);
		Matrix<3> b;
		b.v[0][0] = 1;
		b.v[1][0] = 0;
		b.v[2][0] = 0;
		b = a.mul(b);
		printf("Case %d: %d\n", no++, b.v[0][0]);
	}
	return 0;
}
