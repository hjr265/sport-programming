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

string Z = "PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV";

int c2int(char c) {
	for(int i = 0; i < Z.size(); ++i) if(Z[i] == c)
		return i;
	return -1;
}

int main() {
	int P;
	cin >> P;
	while(P--) {
		int N, d;
		char c, s;
		cin >> N >> c >> d >> s;
		vlong r = 0;
		r |= c2int(c)<<12;
		r |= d<<1;
		r |= s == 'D';
		int g = 1;
		if(r&(1<<16)) {
			g = -1;
			r = (r-1)^((1<<17)-1);
		}
		char f[100];
		sprintf(f, "%0.16lf", (double)r*0.0000152587890625*g);
		for(int i = strlen(f)-1; i >= 3+(f[0] == '-'); --i) {
			if(f[i] == '0')
				f[i] = '\0';
			else
				break;
		}
		printf("%d %s\n", N, f);
	}
	return 0;
}
