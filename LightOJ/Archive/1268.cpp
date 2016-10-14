// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1268
// Unlucky Strings
// matrices, strings
// 
// 
// AC (2012-06-04 09:16:47)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

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



int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		char S[28], W[52];
		scanf("%s", S);
		scanf("%s", W);
		int Sl = strlen(S), Wl = strlen(W);
		Matrix<52> A, B;
		A.v[0][0] = Sl;
		A.v[0][Wl-1] -= 1;
		for(int i = 1; i < Wl; ++i)
			A.v[i][i-1] = 1;
		B.v[0][0] = 1;
		int P[52];
		P[0] = -1;
		P[1] = 0;
		strcat(W, "$");
		for(int i = 2, j = 0; i <= Wl; ) {
			if(W[i-1] == W[j])
				P[i++] = ++j;
			else if(j > 0)
				j = P[j];
			else
				P[i++] = 0;
		}
		for(int i = P[Wl]; i > 0; i = P[i])
			A.v[i][Wl-1] -= 1;
		printf("Case %d: %u\n", no++, A.pow(n).mul(B).v[0][0]);
	}
	return 0;
}
