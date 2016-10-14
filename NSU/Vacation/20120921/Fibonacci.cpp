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

char Fn[800000000];

void build(int n) {
	int a0 = 1, a1 = 1, b;
	for(int i = 0; i <= n; ++i) switch(i) {
	case 0:
		Fn[0] = '0';
		break;
	case 1:
		Fn[0] = '1';
		break;
	case 2:
		Fn[0] = '1', Fn[1] = '0';
		b = 2;
		break;
	default:
		for(int j0 = 0, j1 = b; j0 < a1; ++j0, ++j1, ++b)
			Fn[j1] = Fn[j0];
		Fn[b] = '\0';
		swap(a0, a1);
		a1 += a0;
		break;
	}
}

int n;
char P[100005];

int F[100005];

int kmp(char s[], char w[]) {
	int n = strlen(s), m = strlen(w);
	F[0] = -1;
	F[1] = 0;
	for(int i = 2, j = 0; i < m; ) {
		if(w[i-1] == w[j])
			F[i++] = ++j;
		else if(j > 0)
			j = F[j];
		else
			F[i++] = 0;
	}
	int z = 0;
	for(int i = 0, j = 0; j+i < n; ) {
		if(w[i] == s[j+i]) {
			if(i == m-1) {
				++z;
				j += i-F[i];
				if(F[i] > -1)
					i = F[i];
				else
					i = 0;
				continue;
			}
			++i;
		} else {
			j += i - F[i];
			if(F[i] > -1)
				i = F[i];
			else
				i = 0;
		}
	}
	return z;
}

int main() {
	scanf("%d", &n);
	build(n);
	scanf("%s", P);
	printf("%d\n", kmp(Fn, P));
	return 0;
}
