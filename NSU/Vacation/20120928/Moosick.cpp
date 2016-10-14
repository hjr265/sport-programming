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

int N, C;
vector<int> T, X;

int main() {
	cin >> N;
	for(int i = 0; i < N; ++i) {
		int t;
		cin >> t;
		T.push_back(t);
	}
	cin >> C;
	for(int i = 0; i < C; ++i) {
		int x;
		cin >> x;
		X.push_back(x);
	}
	
	sort(ALL(X));
	
	vector<int> R;
	for(int i = 0; i < N-C+1; ++i) {
		vector<int> S(C);
		copy(T.begin()+i, T.begin()+i+C, S.begin());
		sort(ALL(S));
		bool f = true;
		for(int j = 0; f && j < C; ++j) if(S[j]-X[j] != S[0]-X[0])
			f = false;
		if(f)
			R.push_back(i+1);
	}
	
	cout << R.size() << endl;
	for(int i = 0; i < R.size(); ++i)
		cout << R[i] << endl;
	return 0;
}
