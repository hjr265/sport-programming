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

enum {
	
};

vector<vlong> X, Y;

void initX(vlong l, vlong r) {
	while(r) {
		r /= 2;
		X.push_back(r);
	}
	--l;
	while(l) {
		l /= 2;
		Y.push_back(l);
	}
	for(int i = 0; i < X.size() && i < Y.size(); ++i)
		X[i] -= Y[i];
	for(int i = 0; i < X.size()-1; ++i)
		X[i] = max(0LL, X[i]-X[i+1]);
}

template<int d>
class Matrix {
public:
	vlong v[d][d];
	
	Matrix() {
		SET(v, 0);
	}
	
	Matrix<d> mul(const Matrix<d> &b, vlong m) {
		Matrix<d> r;
		for(int k = 0; k < d; ++k) {
			for(int i = 0; i < d; ++i) {
				for(int j = 0; j < d; ++j)
					r.v[i][j] = (r.v[i][j]+(v[i][k]*b.v[k][j])%m)%m;
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
				r = r.mul(b, m).mod(m);
			b = b.mul(b, m);
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
	vlong m, l, r, k;
	cin >> m >> l >> r >> k;
	
	initX(l, r);
	
	int i = X.size()-1;
	while(k > 0 && i >= 0) {
		k -= X[i];
		if(k > 0)
			--i;
	}
	++i;
	if(k > 0) {
		cout << 1 << endl;
		return 0;
	}
	
	Matrix<2> A, B;
	A.v[0][0] = 1;
	A.v[0][1] = 1;
	A.v[1][0] = 1;
	A.v[1][1] = 0;
	B.v[0][0] = 1;
	B.v[1][0] = 1;
	cout << A.modpow((1LL<<i)-1, m).mul(B, m).mod(m).v[1][0] << endl;
	return 0;
}
