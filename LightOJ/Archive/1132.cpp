// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1132
// Summing up Powers
// matrices
// 
// 
// AC (2012-05-23 23:23:54)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

typedef unsigned int uint;
typedef long long vlong;

class Matrix {
	int d;
public:
	uint v[52][52];
	
	Matrix(int d_) : d(d_) {
		CLR(v);
	}
	
	Matrix mul(const Matrix &b) {
		Matrix r(d);
		for(int k = 0; k < d; ++k) {
			for(int i = 0; i < d; ++i) {
				for(int j = 0; j < d; ++j)
					r.v[i][j] += v[i][k]*b.v[k][j];
			}
		}
		return r;
	}
	
	Matrix pow(vlong p) {
		Matrix r(d), b = *this;
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

uint C[52][52];

int main() {
	CLR(C);
	for(int i = 0; i < 52; ++i)
		C[i][0] = C[i][1] = C[i][i] = 1;
	for(int i = 2; i < 52; ++i) {
		for(int j = 1; j < i; ++j)
			C[i][j] = C[i-1][j]+C[i-1][j-1];
	}
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong N;
		uint K;
		scanf("%lld %u", &N, &K);
		Matrix A(K+2), B(K+2);
		A.v[0][0] = 1;
		for(int i = 0; i <= K; ++i) {
			for(int j = 0; j <= K-i; ++j)
				A.v[i+1][i+j+1] = C[K-i][j];
		}
		for(int j = 0; j <= K; ++j)
			A.v[0][j+1] = A.v[1][j+1];
		B.v[0][0] = 1;
		for(int i = 0; i <= K; ++i)
			B.v[i+1][0] = 1;
		printf("Case %d: %u\n", no++, A.pow(N-1).mul(B).v[0][0]);
	}
	return 0;
}
