// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1332
// Kings in Chessboard
// matrices
// 
// 
// AC (2012-05-28 20:13:35)

#include <cmath>
#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

typedef unsigned int uint;

template<int d>
class Matrix {
public:
	uint v[d][d];
	
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
	
	Matrix<d> pow(uint p) {
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

Matrix<40> A, B;

int main() {
	for(int i0 = 0, k = 1; i0 < 10; ++i0) {
		for(int i1 = i0+2; i1 < 10; ++i1, ++k) {
			B.v[k][0] = 1;
			for(int i2 = 0, l = 1; i2 < 10; ++i2) {
				for(int i3 = i2+2; i3 < 10; ++i3, ++l) if(abs(i0-i2) > 1 && abs(i1-i2) > 1 && abs(i0-i3) > 1 && abs(i1-i3) > 1) {
					A.v[k][l] = 1;
				}
			}
			
		}
	}
	for(int i = 1; i <= 36; ++i)
		A.v[0][i] = 1;
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		printf("Case %d: %u\n", no++, A.pow(n).mul(B).v[0][0]);
	}
	return 0;
}
