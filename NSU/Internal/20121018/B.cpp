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
	int A[2*N+2],
		V[N+2];

public:
	Maxsegtree() {
		clear();
	}
	
	void clear() {
		SET(A, 0);
		SET(V, 0);
		for(int i = N; i < 2*N; ++i)
			A[i] = i-N;
	}
	
	void set(int i, int x) {
		V[i] = x;
		for(i = (i+N)/2; i; i /= 2)
			A[i] = V[A[2*i]] > V[A[2*i+1]] ? A[2*i] : A[2*i+1];
	}
	
	int max(int i, int j) {
		int r = 0;
        for(i += N, j += N; i < j; i /= 2, j /= 2) {
            if(i&1) {
            	r = V[r] > V[A[i]] ? r : A[i];
            	++i;
            }
            if(j&1) {
            	--j;
            	r = V[r] > V[A[j]] ? r : A[j];
            }
        }
        return r;
	}
};

int A[100005];
Maxsegtree<int, 100005> T;

int main() {
	int N;
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
		T.set(i, A[i]);
	}
	
	int Q;
	scanf("%d", &Q);
	while(Q--) {
		char C[2];
		int i, x, y;
		scanf("%s", C);
		switch(C[0]) {
		case 'U':
			scanf("%d %d", &i, &x);
			A[i] = x;
			T.set(i, x);
			break;
		case 'Q':
			scanf("%d %d", &x, &y);
			++y;
			int i = T.max(x, y),
				jl = T.max(x, i),
				jr = T.max(i+1, y);
			int j = jl;	
			if(A[j] < A[jr])
				j = jr;
			printf("%lld\n", (vlong)A[i]+(vlong)A[j]);
			break;
		}
	}
	return 0;
}
