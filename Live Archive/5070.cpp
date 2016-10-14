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

const double EPS = 1e-8;
const double PI = acos(-1.0);

enum {
	
};

template<class T, int d>
class Matrix {
public:
	T V[d][d];
	
	Matrix() {
		clear();
	}
	
	void clear() {
		SET(V, 0);
	}
	
	Matrix add(const Matrix &m2) const {
		Matrix r;
		for(int i = 0; i < d; ++i) {
			for(int j = 0; j < d; ++j)
				r.V[i][j] = V[i][j] + m2.V[i][j];
		}
		return r;
	}
	
	Matrix mul(const Matrix &m2) const {
		Matrix r;
		for(int k = 0; k < d; ++k) {
			for(int i = 0; i < d; ++i) {
				for(int j = 0; j < d; ++j)
					r.V[i][j] += V[i][k]*m2.V[k][j];
			}
		}
		return r;
	}
	
	Matrix pow(int p) const {
		Matrix r, b = *this;
		for(int i = 0; i < d; ++i)
			r.V[i][i] = 1;
		for(; p; p /= 2, b = b.mul(b)) {
			if(p%2)
				r = r.mul(b);
		}
		return r;
	}
	
	bool solve(int h) {
		for(int i = 0, i3 = 0; i < h; ++i, ++i3) {
			int mi = i;
			for(int i2 = i+1; i2 < h; ++i2) if(abs(V[i2][i]) > abs(V[mi][i]))
				mi = i2;
			for(int j = 0; j < d; ++j)
				swap(V[mi][j], V[i][j]);
			if(abs(V[i][i]) < EPS)
				return false;
			for(int i2 = i+1; i2 < h; ++i2) {
				T c = V[i2][i]/V[i][i];
				for(int j = i; j < d; ++j)
					V[i2][j] -= V[i][j]*c;
			}
		}
		for(int i = h-1; i >= 0; --i) {
			T c = V[i][i];
			for(int i2 = 0; i2 < i; ++i2) {
				for(int j = h; j >= i; --j)
					V[i2][j] -= V[i][j]*V[i2][i]/c;
			}
			V[i][i] /= c;
			for(int j = h; j < d; ++j)
				V[i][j] /= c;
		}
		return true;
	}
};

Matrix<double, 630> MX;

int main() {
	int m, n, d;
	while(scanf("%d %d %d", &m, &n, &d) == 3 && (m != 0 || n != 0 || d != 0)) {
		MX.clear();
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j)
				scanf("%lf", &MX.V[i*m+j][n*m]);
		}
		
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				for(int i2 = 0; i2 < n; ++i2) {
					for(int j2 = 0; j2 < m; ++j2) if(abs(i-i2)+abs(j-j2) == d || i == i2 && j == j2)
						MX.V[i2*m+j2][i*m+j] = 1;
				}
			}
		}
		
		bool k = MX.solve(n*m);
		printf("%d\n", k);
	}
	return 0;
}
