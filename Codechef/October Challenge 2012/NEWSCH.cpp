// In the name of Allah, Most Gracious, Most Merciful

// /
// 
// 
// 
// 
// ??

#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define SET(c, v) memset(c, v, sizeof(c))
#define LEN(c) (sizeof(c)/sizeof(c[0]))
#define ALL(c) c.begin(), c.end()
#define SLC(c, n) c, c+(n)

using namespace std;

typedef unsigned int uint;
typedef long long vlong;
typedef unsigned long long uvlong;

const double EPS = 1e-12;
const double PI = acos(-1.0);
const vlong MOD = 1000000007;

enum {
	
};

template<class T, int d>
class Matrix {
public:
	T v[d][d];
	
	Matrix() {
		SET(v, 0);
	}
	
	Matrix<T, d> mul(const Matrix<T, d> &m2) const {
		Matrix<T, d> r;
		for(int k = 0; k < d; ++k) {
			for(int i = 0; i < d; ++i) {
				for(int j = 0; j < d; ++j)
					r.v[i][j] = (r.v[i][j]+(v[i][k]*m2.v[k][j])%MOD)%MOD;
			}
		}
		return r;
	}
	
	Matrix<T, d> pow(int p) const {
		Matrix<T, d> r, b = *this;
		for(int i = 0; i < d; ++i)
			r.v[i][i] = 1;
		for(; p; p /= 2, b = b.mul(b)) {
			if(p%2)
				r = r.mul(b);
		}
		return r;
	}
	
	void print() {
		for(int i = 0; i < d; ++i) {
			for(int j = 0; j < d; ++j)
				printf("%lld ", v[i][j]);
			printf("\n");
		}
	}
};

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		
		Matrix<vlong, 4> A, B;
		B.v[0][0] = 1;
		for(int j = 0; j < 4; ++j) {
			for(int k = 0; k < 4; ++k) if(j != k)
				++A.v[j][k];
		}
		
		Matrix<vlong, 4> R = A.pow(N-2).mul(B);
		vlong Z = R.v[0][0]*3;
		for(int j = 1; j < 4; ++j)
			Z = (Z+R.v[j][0]*2)%MOD;
		Z *= 4;
		printf("%lld\n", Z%MOD);
	}
	return 0;
}
