// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1142
// Summing up Powers (II)
// matrices
// 
// 
// AC (2012-06-08 15:51:25)

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
	
	Matrix<d> add(const Matrix<d> &b) {
		Matrix<d> r;
		for(int i = 0; i < d; ++i) {
			for(int j = 0; j < d; ++j)
				r.v[i][j] = v[i][j]+b.v[i][j];
		}
		return r;
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

	Matrix<d> mod(int m) {
		Matrix<d> r;
		for(int i = 0; i < d; ++i) {
			for(int j = 0; j < d; ++j)
				r.v[i][j] = v[i][j]%m;
		}
		return r;
	}
	
	static Matrix<d> eye() {
		Matrix<d> r;
		for(int i = 0; i < d; ++i)
			r.v[i][i] = 1;
		return r;
	}
};

template<int d>
class MMatrix {
public:
	Matrix<d> v[2][2];
	
	MMatrix<d> mul(const MMatrix<d> &b) {
		MMatrix<d> r;
		for(int k = 0; k < 2; ++k) {
			for(int i = 0; i < 2; ++i) {
				for(int j = 0; j < 2; ++j)
					r.v[i][j] = r.v[i][j].add(v[i][k].mul(b.v[k][j]));
			}
		}
		return r;
	}
	
	MMatrix modpow(int p, int m) {
		MMatrix<d> r, b = *this;
		for(int i = 0; i < 2; ++i)
			r.v[i][i] = Matrix<d>::eye();
		for(; p; p /= 2) {
			b = b.mod(m);
			if(p%2)
				r = r.mul(b).mod(m);
			b = b.mul(b);
		}
		return r;
	}
	
	MMatrix mod(int m) {
		MMatrix<d> r;
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j < 2; ++j)
				r.v[i][j] = v[i][j].mod(m);
		}
		return r;
	}
	
	void print() {
		for(int i = 0; i < 2*d; ++i) {
			for(int j = 0; j < 2*d; ++j)
				printf("%2d", v[i/d][j/d].v[i%d][j%d]);
			printf("\n");
		}
	}
};



int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, k;
		scanf("%d %d", &n, &k);
		Matrix<32> M;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j)
				scanf("%d", &M.v[i][j]);
		}
		M = M.mod(10);
		MMatrix<32> A, B;
		A.v[0][0] = Matrix<32>::eye();
		A.v[0][1] = M;
		A.v[1][0] = Matrix<32>();
		A.v[1][1] = M;
		B.v[0][0] = Matrix<32>();
		B.v[1][0] = Matrix<32>::eye();
		Matrix<32> R = A.modpow(k, 10).mul(B).mod(10).v[0][0];
		printf("Case %d:\n", no++);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j)
				printf("%d", R.v[i][j]);
			printf("\n");
		}
	}
	return 0;
}
