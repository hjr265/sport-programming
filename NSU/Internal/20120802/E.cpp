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

priority_queue<int> X[7];

int main() {
	int N, P;
	cin >> N >> P;
	vlong Z = 0;
	while(N--) {
		int S, F;
		cin >> S >> F;
		while(!X[S].empty() && X[S].top() > F) {
			X[S].pop();
			++Z;
		}
		if(X[S].empty() || X[S].top() != F) {
			X[S].push(F);
			++Z;
		}
	}
	cout << Z << endl;
	return 0;
}
