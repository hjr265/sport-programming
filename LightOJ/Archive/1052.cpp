// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1052
// String Growth
// matrices
// 
// 
// AC (2012-05-23 21:43:41)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

typedef long long vlong;

const vlong mod = 1000000007LL;

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
		vlong N, X, M, Y, K;
		scanf("%lld %lld %lld %lld %lld", &N, &X, &M, &Y, &K);
		if(M < N) {
			swap(N, M);
			swap(X, Y);
		}
		Matrix<2> P;
		P.v[0][0] = 1;
		P.v[0][1] = 1;
		P.v[1][0] = 1;
		P.v[1][1] = 0;
		Matrix<2> Pn = P.modpow(N, mod), Pm = P.modpow(M, mod);
		Matrix<2> Q;
		printf("Case %d: ", no++);
		bool r = false;
		if((X*Pm.v[0][1]-Y*Pn.v[0][1])%(Pn.v[0][0]*Pm.v[0][1]-Pm.v[0][0]*Pn.v[0][1]) == 0) {
			Q.v[0][0] = (X*Pm.v[0][1]-Y*Pn.v[0][1])/(Pn.v[0][0]*Pm.v[0][1]-Pm.v[0][0]*Pn.v[0][1]);
			if(Q.v[0][0] >= 0 && (X-Pn.v[0][0]*Q.v[0][0])%Pn.v[0][1] == 0) {
				Q.v[1][0] = (X-Pn.v[0][0]*Q.v[0][0])/Pn.v[0][1];
				if(Q.v[1][0] >= 0) {
					printf("%lld\n", P.modpow(K, mod).mul(Q).v[0][0]%mod);
					r = true;
				}
			}
		}
		if(!r)
			printf("Impossible\n");
	}
	return 0;
}
