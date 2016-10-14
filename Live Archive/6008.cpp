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

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N1, N2;
		cin >> N1;
		vector<int> A;
		for(int i = 0; i < N1; ++i) {
			int x;
			cin >> x;
			A.push_back(x);
		}
		cin >> N2;
		int R = 1<<28;
		for(int i = 0; i < N2; ++i) {
			int x;
			cin >> x;
			for(int j = 0; j < N1; ++j)
				R = min(R, abs(x-A[j]));
		}
		cout << R << endl;
	}
	return 0;
}
