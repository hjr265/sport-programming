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
class Maxsegtree {
	T V[2*N+2];

public:
	Maxsegtree() {
		clear();
	}
	
	void clear() {
		SET(V, 0);
	}
	
	void set(int i, int x) {
		V[i] = x;
		for(i = (i+N)/2; i; i /= 2)
			V[i] = max(V[2*i], V[2*i+1]);
	}
	
	int max(int i, int j) {
		int r = 0;
        for(i += N, j += N; i < j; i /= 2, j /= 2) {
            if(i&1)
            	r = max(r, V[i++]);
            if(j&1)
            	r = max(r, V[--j]);
        }
        return r;
	}
};

Maxsegtree<char, 100005> MT[9593];

bool S[100005];
map<int, int> PX;

int main() {
	PX[2] = 1;
	for(vlong i = 3, x = 2; i < 100005; i += 2) if(!S[i]) {
		PX[i] = x++;
		for(vlong j = i*i; j < 100005; j += 2*i)
			S[j] = true;
	}
	cout << (int)PX.size() << endl;
	return 0;
}
