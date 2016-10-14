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

/*vector<int> P;

int find(int i, int x) {
	if(i == 1)
		return max(x, i);
	return max(find(P[i-1], max(i, P[i-1])), i);
}

vlong F[22];

int main() {
	int n = 7;
	
	vector<int> V;
	for(int i = 1; i <= n; ++i)
		V.push_back(i);
	
	int X[50];
	SET(X, 0);
	
	do {
		
		P = V;
		
		++X[find(P[0], 1)];
		
	} while(next_permutation(ALL(V)));
	
	for(int i = 1; i <= n; ++i)
		cout << X[i] << endl;
	
	return 0;
}*/

vlong F[22];

int main() {
	F[0] = 1;
	for(vlong i = 1; i < 22; ++i)
		F[i] = F[i-1]*i;
	int P;
	cin >> P;
	while(P--) {
		int N, n, k;
		cin >> N >> n >> k;
		vlong R = F[n-k];
		for(vlong i = 3; i <= k; ++i)
			R *= n-i+3;
		cout << N << " " << R << endl;
	}
	return 0;
}
