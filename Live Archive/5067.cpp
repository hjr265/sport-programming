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

map<string, int> M;
vector<int> E[1102];
int V[1102];

int count(int u) {
	if(V[u])
		return 0;
	V[u] = true;
	if(E[u].size() == 0)
		return 1;
	int r = 0;
	for(int i = 0; i < E[u].size(); ++i)
		r += count(E[u][i]);
	return r;
}

int main() {
	int n;
	while(cin >> n && n != 0) {
		M.clear();
		for(int i = 0; i < 1102; ++i)
			E[i].clear();
		
		while(n--) {
			string l;
			cin >> l;
			
			for(int i = 0; i < l.size(); ) {
				int x = 0;
				for(int j = i; j < l.size(); ++j) {
					if(l[j] == ':' || l[j] == ',' || l[j] == '.') {
						string g = l.substr(i, j-i);
						if(M[g] == 0)
							M[g] = M.size();
						if(x == 0)
							x = M[g];
						else
							E[x].push_back(M[g]);
						i = j+1;
					}
				}
			}
		}
		
		SET(V, 0);
		cout << count(1) << endl;
	}
	return 0;
}
