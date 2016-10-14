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

const string Cs[] = {
	"Carrots",
	"Kiwis",
	"Grapes"
};

int main() {
	int n, m, k, t;
	scanf("%d %d %d %d", &n, &m, &k, &t);
	
	vector<int> W;
	while(k--) {
		int a, b;
		scanf("%d %d", &a, &b);
		
		W.push_back(m*(a-1)+b);
	}
	sort(ALL(W));
	/*for(int i = 0; i < W.size(); ++i)
		printf("%d\n", W[i]);*/
	
	/*for(int x = 1; x <= n*m; ++x) {
		vector<int>::iterator wsit = lower_bound(ALL(W), x);
		int wsi = wsit-W.begin();
		bool isw = (wsit != W.end() && *wsit == x);
		printf("%2d %d %d %d\n", x, wsi, isw, (x-wsi-1)%3);
	}*/
	
	while(t--) {
		int i, j;
		scanf("%d %d", &i, &j);
		
		int x = m*(i-1)+j;
		
		vector<int>::iterator wsit = lower_bound(ALL(W), x);
		int wsi = wsit-W.begin();
		bool isw = (wsit != W.end() && *wsit == x);
		
		printf("%s\n", isw ? "Waste" : Cs[(x-wsi-1)%3].c_str());
	}
	return 0;
}
