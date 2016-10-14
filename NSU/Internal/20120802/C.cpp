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

vlong A, B;
vlong Ax[17], Bx[17];

void vlong2arr(vlong N, vlong A[]) {
	for(int i = 17-1; i >= 0; --i, N /= 10)
		A[i] = N%10; 
}

struct Dpret {
	vlong v, c;
	
	Dpret() {}
	Dpret(vlong v_, vlong c_) : v(v_), c(c_) {}
};

vlong T[18];
Dpret D[17][11][17][2];

Dpret dp(vlong A, vlong Ax[], int i, int d, int c, bool s) {
	if(i == 17)
		return Dpret(0, 1);
	Dpret &r = D[i][d][c][s];
	if(r.v == -1) {
		r.v = 0;
		r.c = 0;
		for(vlong x = 0; s ? x <= Ax[i] : x < 10; ++x) if(x != d) {
			for(vlong j = i+1; j <= 17; ++j) {
				if(s) {
					vlong q = 0;
					for(int k = i; k < j; ++k)
						q *= 10, q += x;
					if(q < (A/T[17-j])%T[j-i]) {
						Dpret t = dp(A, Ax, j, x, j-i, false);
						r.v += t.v+x*(j-i)*(j-i)*t.c;
						r.c += t.c;
					} else if(q == (A/T[17-j])%T[j-i]) {
						Dpret t = dp(A, Ax, j, x, j-i, s);
						r.v += t.v+x*(j-i)*(j-i)*t.c;
						r.c += t.c;
					}
				} else {
					Dpret t = dp(A, Ax, j, x, j-i, false);
					r.v += t.v+x*(j-i)*(j-i)*t.c;
					r.c += t.c;
				}
			}
		}
	}
	return r;
}

int main() {
	T[0] = 1;
	for(int i = 1; i < 18; ++i)
		T[i] = T[i-1]*10LL;
	while(cin >> A >> B) {
		A -= 1;
		vlong2arr(A, Ax);
		vlong2arr(B, Bx);
		SET(D, -1);
		vlong Z = dp(B, Bx, 0, 10, 0, true).v;
		SET(D, -1);
		Z -= dp(A, Ax, 0, 10, 0, true).v;
		cout << Z << endl;
	}
	return 0;
}
