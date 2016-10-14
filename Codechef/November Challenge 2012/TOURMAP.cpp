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

vector<string> V;
map<string, pair<string, int> > E;
map<string, int> ID;
map<string, int> OD;

int main() {
	int T;
	cin >> T;
	while(T--) {
		V.clear();
		E.clear();
		ID.clear();
		OD.clear();
		
		int N;
		cin >> N;
		for(int i = 0; i < N-1; ++i) {
			string A, B;
			int C;
			cin >> A >> B;
			cin >> C;
			string _g;
			cin >> _g;
			if(!OD[A] && !ID[A])
				V.push_back(A);
			if(!OD[B] && !ID[B])
				V.push_back(B);
			E[A] = pair<string, int>(B, C);
			++OD[A];
			++ID[B];
		}
		
		string S, D;
		for(int i = 0; i < V.size(); ++i) {
			if(ID[V[i]] == 0)
				S = V[i];
			if(OD[V[i]] == 0)
				D = V[i];
		}
		
		int R = 0;
		while(S != "") {
			pair<string, int> X = E[S];
			if(X.first != "")
				cout << S << " " << X.first << " " << X.second << "$" << endl;
			R += X.second;
			S = X.first;
		}
		cout << R << "$" << endl;
	}
	return 0;
}
