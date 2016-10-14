// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1160
// Discovering Paths in Grid
// matrices
// 
// 
// AC (2012-06-09 10:15:55)

#include <cstdio>
#include <cstring>
#include <vector>

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
					r.v[i][j] += (v[i][k]*b.v[k][j])%1000000007LL;
			}
		}
		return r;
	}
	
	Matrix<d> modpow(vlong p) {
		Matrix<d> r, b = *this;
		for(int i = 0; i < d; ++i)
			r.v[i][i] = 1;
		for(; p; p /= 2) {
			b = b.mod(1000000007LL);
			if(p%2)
				r = r.mul(b).mod(1000000007LL);
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

vector<int> S;
Matrix<40> A;

bool okay(int x, int y) {
	for(; x || y; x >>= 1, y >>= 1) {
		if(x&1) {
			if(!(y&2))
				return false;
			x ^= 1, y ^= 2;
		}
		if(y&1) {
			if(!(x&2))
				return false;
			y ^= 1, x ^= 2;
		}
	}
	return true;
}

int main() {
	for(int i = 0; i < 1<<7; ++i) {
		int x = i, k = 0;
		for(; x; x >>= 1)
			k += x&1;
		if(k == 4)
			S.push_back(i);
	}
	for(int i = 0; i < S.size(); ++i) {
		for(int j = 0; j < S.size(); ++j) if(okay(S[i], S[j]))
			A.v[i][j] = 1;
	}
	for(int i = 0; i < S.size(); ++i)
		A.v[39][i] = 1;
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong N;
		scanf("%lld", &N);
		Matrix<40> B;
		int x = 0;
		for(int i = 0; i < 7; ++i) {
			x <<= 1;
			int p;
			scanf("%d", &p);
			if(p != 0)
				x |= 1;
		}
		for(int i = 0; i < S.size(); ++i) if(S[i] == x) {
			B.v[i][0] = 1;
			break;
		}
		printf("Case %d: %lld\n", no++, A.modpow(N).mul(B).v[39][0]%mod);
	}
	return 0;
}
