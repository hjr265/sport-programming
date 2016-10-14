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

int g, Sl;
char G[3002], S[3000002];
int Gc[54], Sc[54];

int char2int(char c) {
	if(c >= 'A' && c <= 'Z')
		return c-'A'+26;
	return c-'a';
}

int main() {
	scanf("%d %d", &g, &Sl);
	scanf("%s %s", &G, &S);
	for(int i = 0; i < g; ++i)
		++Gc[char2int(G[i])];
	int Z = 0;
	for(int i = 0; i < Sl; ++i) {
		if(i >= g)
			--Sc[char2int(S[i-g])];
		++Sc[char2int(S[i])];
		bool k = true;
		for(int j = 0; k && j < 54; ++j) if(Gc[j] != Sc[j])
			k = false;
		if(k)
			++Z;
	}
	cout << Z << endl;
	return 0;
}
