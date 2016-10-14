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

int main() {
	int P;
	scanf("%d", &P);
	while(P--) {
		int N;
		char Ds[100];
		scanf("%d %s", &N, Ds);
		bool f = false;
		if(Ds[0] == '-' && Ds[1] == '1') {
			for(int i = 3; Ds[i]; ++i) if(Ds[i] != '0') {
				f = true;
				break;
			}
		}
		if(Ds[0] == '1')
			f = true;
		double D;
		sscanf(Ds, "%lf", &D);
		if(f || D-(-1.0) < -EPS || D-1.0 > EPS) {
			cout << N << " INVALID VALUE" << endl;
			continue;
		}
		int g = 1;
		if(D < 0)
			g = -1, D *= -1;
		D /= 0.0000152587890625;
		vlong Dl = (vlong)D;
		if(g == -1)
			Dl = (Dl^((1<<17)-1))+1;
		cout << N << " " << Z[(Dl>>12)&((1<<5)-1)] << " " << ((Dl>>1)&((1<<11)-1)) << " " << (Dl&1 ? 'D' : 'F') << endl;
	}
	return 0;
}
