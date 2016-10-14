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

class Trie {
	struct Node {
		int C[26], w, d;
	};
	
	Node T[1000005];
	int n;

public:
	Trie() {
		clear();
	}
	
	void clear() {
		SET(T, 0);
		n = 2;
	}
	
	void add(char S[]) {
		int p = 1;
		for(int i = 0; S[i]; ++i) {
			int x = T[p].C[S[i]-'a'];
			if(x == 0)
				x = n++;
			++T[x].w;
			T[x].d = i+1;
			T[p].C[S[i]-'a'] = x;
			p = x;
		}
	}
	
	vlong pren() {
		int r = 0;
		for(int i = 2; i < n; ++i) if(T[i].w > 1)
			r += T[i].w;
		return r;
	}
};

Trie X;
char S[1000005];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		X.clear();
		
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%s", S);
			X.add(S);
		}

		printf("%d\n", X.pren()+n);
	}
	return 0;
}
