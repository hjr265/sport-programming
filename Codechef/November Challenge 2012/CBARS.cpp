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
const int MOD = 1000000007;

enum {
	
};

template<class T, int d>
class Matrix {	
public:
	T v[d][d];

	Matrix() {
		SET(v, 0);
	}
	
	Matrix<T, d> mul(const Matrix<T, d> m2) const {
		Matrix<T, d> r;
		for(int k = 0; k < d; ++k) {
			for(int i = 0; i < d; ++i) {
				for(int j = 0; j < d; ++j)
					r.v[i][j] = (r.v[i][j]+((v[i][k]%MOD)*(m2.v[k][j]%MOD))%MOD)%MOD;
			}
		}
		return r;
	}
	
	Matrix<T, d> pow(vlong p) const {
		Matrix<T, d> r, b = *this;
		for(int i = 0; i < d; ++i)
			r.v[i][i] = 1;
		for(; p; p /= 2, b = b.mul(b)) {
			if(p%2)
				r = r.mul(b);
		}
		return r;
	}
};

int main() {
	vlong a, b;
	scanf("%lld %lld", &a, &b);
	Matrix<vlong, 20> A, B;
	switch(a) {
	case 1:
		B.v[0][0] = 1;
		
		A.v[0][0] = 2;
		
		printf("%lld\n", (A.pow(b).mul(B).v[0][0]+MOD)%MOD);
		break;
		
	case 2:
		B.v[0][0] = 14;
		B.v[1][0] = 4;
		
		A.v[0][0] = 3;
		A.v[0][1] = 2;
		A.v[1][0] = 1;
		
		printf("%lld\n", (A.pow(b-1).mul(B).v[1][0]+MOD)%MOD);
		break;
		
	case 3:
		B.v[0][0] = 322;
		B.v[1][0] = 50;
		B.v[2][0] = 8;
		
		// a(n)=6*a(n-1)+3*a(n-2)-2*a(n-3)
		A.v[0][0] = 6;
		A.v[0][1] = 3;
		A.v[0][2] = -2;
		A.v[1][0] = 1;
		A.v[2][1] = 1;
		
		printf("%lld\n", (A.pow(b-1).mul(B).v[2][0]+MOD)%MOD);
		break;
		
	case 4:
		B.v[0][0] = 275690;
		B.v[1][0] = 23858;
		B.v[2][0] = 2066;
		B.v[3][0] = 178;
		B.v[4][0] = 16;
		
		// a(n)=10*a(n-1)+20*a(n-2)-21*a(n-3)-30*a(n-4)+8*a(n-5)
		A.v[0][0] = 10;
		A.v[0][1] = 20;
		A.v[0][2] = -21;
		A.v[0][3] = -30;
		A.v[0][4] = 8;
		A.v[1][0] = 1;
		A.v[2][1] = 1;
		A.v[3][2] = 1;
		A.v[4][3] = 1;
		
		printf("%lld\n", (A.pow(b-1).mul(B).v[4][0]+MOD)%MOD);
		break;
		
	case 5:
		B.v[0][0] = 1074033301458LL%MOD;
		B.v[1][0] = 51630303190LL%MOD;
		B.v[2][0] = 2481942354LL%MOD;
		B.v[3][0] = 119310334LL%MOD;
		B.v[4][0] = 5735478;
		B.v[5][0] = 275690;
		B.v[6][0] = 13262;
		B.v[7][0] = 634;
		B.v[8][0] = 32;
		
		// a(n)=21*a(n-1)+9*a(n-2)-278*a(n-3)+73*a(n-4)+790*a(n-5)-662*a(n-6)+29*a(n-7)+69*a(n-8)-10*a(n-9)
		A.v[0][0] = 21;
		A.v[0][1] = 9;
		A.v[0][2] = -278;
		A.v[0][3] = 73;
		A.v[0][4] = 790;
		A.v[0][5] = -662;
		A.v[0][6] = 29;
		A.v[0][7] = 69;
		A.v[0][8] = -10;
		A.v[1][0] = 1;
		A.v[2][1] = 1;
		A.v[3][2] = 1;
		A.v[4][3] = 1;
		A.v[5][4] = 1;
		A.v[6][5] = 1;
		A.v[7][6] = 1;
		A.v[8][7] = 1;
		
		printf("%lld\n", (A.pow(b-1).mul(B).v[8][0]+MOD)%MOD);
		break;
		
	case 6:
		B.v[0][0] = 927568251;
		B.v[1][0] = 394456513;
		B.v[2][0] = 88893786;
		B.v[3][0] = 438338918;
		B.v[4][0] = 550722139;
		B.v[5][0] = 54569745;
		B.v[6][0] = 486842637;
		B.v[7][0] = 533541711;
		B.v[8][0] = 8790181730741270LL%MOD;
		B.v[9][0] = 234710735573170LL%MOD;
		B.v[10][0] = 6267120468434LL%MOD;
		B.v[11][0] = 167341334542LL%MOD;
		B.v[12][0] = 4468252414LL%MOD;
		B.v[13][0] = 119310334;
		B.v[14][0] = 3185462;
		B.v[15][0] = 85126;
		B.v[16][0] = 2258;
		B.v[17][0] = 64;
		
		// a(n)=36*a(n-1)+120*a(n-2)-2391*a(n-3)-3905*a(n-4)+50702*a(n-5)+27152*a(n-6)-396016*a(n-7)+154999*a(n-8)+751787*a(n-9)-499260*a(n-10)-410368*a(n-11)+355981*a(n-12)+38077*a(n-13)-70276*a(n-14)+6203*a(n-15)+3386*a(n-16)-622*a(n-17)+28*a(n-18)
		A.v[0][0] = 36;
		A.v[0][1] = 120;
		A.v[0][2] = -2391;
		A.v[0][3] = -3905;
		A.v[0][4] = 50702;
		A.v[0][5] = 27152;
		A.v[0][6] = -396016;
		A.v[0][7] = 154999;
		A.v[0][8] = 751787;
		A.v[0][9] = -499260;
		A.v[0][10] = -410368;
		A.v[0][11] = 355981;
		A.v[0][12] = 38077;
		A.v[0][13] = -70276;
		A.v[0][14] = 6203;
		A.v[0][15] = 3386;
		A.v[0][16] = -622;
		A.v[0][17] = 28;
		
		A.v[1][0] = 1;
		A.v[2][1] = 1;
		A.v[3][2] = 1;
		A.v[4][3] = 1;
		A.v[5][4] = 1;
		A.v[6][5] = 1;
		A.v[7][6] = 1;
		A.v[8][7] = 1;
		A.v[9][8] = 1;
		A.v[10][9] = 1;
		A.v[11][10] = 1;
		A.v[12][11] = 1;
		A.v[13][12] = 1;
		A.v[14][13] = 1;
		A.v[15][14] = 1;
		A.v[16][15] = 1;
		A.v[17][16] = 1;
		
		printf("%lld\n", (A.pow(b-1).mul(B).v[17][0]+MOD)%MOD);
		break;
	}
	return 0;
}
