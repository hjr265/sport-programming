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
vector<pair<string, double> > V;
char B[35];

int main() {
	int T;
	scanf("%d", &T);
	gets(B);
	gets(B);
	while(T--) {
		M.clear();
		V.clear();
		
		int L = 0;
		while(true) {
			if(gets(B) == NULL || !B[0]) {
				break;
			}
			++M[string(B)];
			++L;
		}
		
		for(map<string, int>::iterator it = M.begin(); it != M.end(); ++it) {
			V.push_back(pair<string, double>(it->first, double(it->second) / double(L) * 100));
		}
		sort(ALL(V));
		
		for(int i = 0; i < V.size(); ++i) {
			printf("%s %0.4lf\n", V[i].first.c_str(), V[i].second);
		}
		
		if(T != 0) {
			printf("\n");
		}
	}
	return 0;
}
