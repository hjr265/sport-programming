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

map<int, int> M;
set<int> A, B;

void insert(int k) {
	if(M[k])
		A.insert(k);
	B.insert(k);
	++M[k];
}

void delete_(int k) {
	if(!M[k])
		return;
	if(M[k] == 1)
		B.erase(k);
	if(M[k] == 2)
		A.erase(k);
	--M[k];
}

void status() {
	if(A.size() > 0 && B.size() > 1)
		printf("both\n");
	else if(A.size() > 0 && B.size() <= 1)
		printf("homo\n");
	else if(A.size() == 0 && B.size() > 1)
		printf("hetero\n");
	else
		printf("neither\n");
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		char p[12];
		int k;
		scanf("%s %d", p, &k);
		switch(p[0]) {
		case 'i':
			insert(k);
			break;
		case 'd':
			delete_(k);
			break;
		}
		status();
	}
	return 0;
}
