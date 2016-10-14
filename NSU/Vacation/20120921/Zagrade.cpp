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

string S;

vector<pair<int, int> > P;

bool X[202];

vector<string> R;

int main() {
	cin >> S;
	
	stack<int> K;
	for(int i = 0; i < S.size(); ++i) switch(S[i]) {
	case '(':
		K.push(i);
		break;
	case ')':
		P.push_back(pair<int, int>(K.top(), i));
		K.pop();
		break;
	}
	
	for(int x = 1; x < (1<<P.size()); ++x) {
		SET(X, 0);
		for(int i = 0; i < P.size(); ++i) if(x&(1<<i))
			X[P[i].first] = X[P[i].second] = true;
		
		string r = "";
		for(int i = 0; i < S.size(); ++i) if(!X[i])
			r += S[i];
			
			R.push_back(r);
	}
	
	sort(ALL(R));
	R.resize(unique(ALL(R))-R.begin());
	
	for(int i = 0; i < R.size(); ++i)
		cout << R[i] << endl;
	return 0;
}
