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

char A[20005], B[20005];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", A);
		scanf("%s", B);
		
		int vA[10], vB[10];
		SET(vA, 0);
		SET(vB, 0);
		for(int i = 0; A[i]; ++i)
			++vA[A[i]-'0'], ++vB[B[i]-'0'];
		
		int R[2];
		SET(R, 0);
		
		for(int i = 6; i >= 0; --i) if(i != 4) {
			int x = min(vB[7], vA[i]);
			R[0] += x;
			vB[7] -= x;
			vA[i] -= x;
		}
		for(int i = 6; i >= 0; --i) if(i != 4) {
			int x = min(vA[7], vB[i]);
			R[0] += x;
			vA[7] -= x;
			vB[i] -= x;
		}
		for(int i = 3; i >= 0; --i) {
			int x = min(vB[4], vA[i]);
			R[1] += x;
			vB[4] -= x;
			vA[i] -= x;
		}
		for(int i = 3; i >= 0; --i) {
			int x = min(vA[4], vB[i]);
			R[1] += x;
			vA[4] -= x;
			vB[i] -= x;
		}
		
		R[0] += min(vA[7], vB[4]);
		vA[7] -= min(vA[7], vB[4]);
		vB[4] -= min(vA[7], vB[4]);
		R[0] += min(vA[7], R[1]);
		vA[7] -= min(vA[7], R[1]);
		R[1] -= min(vA[7], R[1]);
		R[0] += min(vB[7], vA[4]);
		vB[7] -= min(vB[7], vA[4]);
		vA[4] -= min(vB[7], vA[4]);
		R[0] += min(vB[7], R[1]);
		vB[7] -= min(vB[7], R[1]);
		R[1] -= min(vB[7], R[1]);
		
		R[0] += min(vA[7], vB[7]);
		R[1] += min(vA[4], vB[4]);
		
		for(int i = 0; i < R[0]; ++i)
			printf("7");
		for(int i = 0; i < R[1]; ++i)
			printf("4");
		printf("\n");
	}
}
