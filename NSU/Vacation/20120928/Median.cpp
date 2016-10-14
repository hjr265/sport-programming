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

int A[100002], 
	Z[100002],
	Q[100002];

int main() {
	int N, X;
	cin >> N >> X;
	for(int i = 1; i <= N; ++i) {
		int H;
		cin >> H;
		A[i] = H >= X ? 1 : -1;
		Z[i] = Z[i-1]+A[i];
	}
	for(int i = N; i > 0; --i) {
		Q[i] = i+1;
		if(A[i] == A[i+1])
			Q[i] = Q[i+1];
	}
	
	vlong R = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = i+1; j <= N; ) {
			if(Z[j]-Z[i] >= 0) {
				++R;
				if(A[j] == 1) {
					R += Q[j]-j-1;
					j = Q[j];
				} else {
					++j;
				}
			} else {
				++j;
			}
		}
	}
	
	cout << R << endl;
	return 0;
}
