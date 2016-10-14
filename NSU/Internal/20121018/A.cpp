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

template<class T, int N>
class Sumsegtree {
public:
	T V[2*N+2][5];

	Sumsegtree() {
		clear();
	}
	
	void clear() {
		SET(V, 0);
	}
	
	void set(int i, int x) {
		V[i+N][4] = V[i+N][3] = V[i+N][2] = V[i+N][1] = V[i+N][0] = x;
		for(i = (i+N)/2; i; i /= 2) {
			V[i][1] = V[2*i][1]+V[2*i+1][1];
			V[i][2] = max(V[2*i][2], V[2*i][1]+V[2*i+1][2]);
			V[i][3] = max(V[2*i+1][3], V[2*i][3]+V[2*i+1][1]);
			V[i][4] = max(max(V[2*i][4], V[2*i+1][4]), V[2*i][3]+V[2*i+1][2]);
		}
	}
	
	int maxsum(int i, int j) {
		int r = 0;
        for(i += N, j += N; i < j; i /= 2, j /= 2) {
            if(i&1) {
            	r = max(r, V[i][4]);
            	++i;
            }
            if(j&1) {
            	--j;
            	r = max(r, V[j][4]);
            }
        }
        return r;
	}
};

Sumsegtree<int, 100005> ST;

int main() {
	ST.set(1, 5);
	ST.set(2, 5);
	ST.set(3, 5);
	cout << ST.maxsum(1, 5) << endl;
	return 0;
}
