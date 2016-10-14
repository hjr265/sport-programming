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

template<class T>
struct Triplet {
	T first, second, third;
	
	Triplet(T first_, T second_, T third_) : first(first_), second(second_), third(third_) {}
};

int N, K;
vector<Triplet<int> > P;
int C[260][260][260];
int S[260][260][260];

int main() {
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i) {
		int R, G, B;
		scanf("%d %d %d", &R, &G, &B);
		++R, ++G, ++B;
		++C[R][G][B];
		P.push_back(Triplet<int>(R, G, B));
	}
	for(int i = 1; i < 55; ++i) {
		for(int j = 1; j < 55; ++j) {
			for(int k = 1; k < 55; ++k)
				S[i][j][k] = C[i][j][k]+(S[i-1][j][k]+S[i][j-1][k]+S[i][j][k-1]-S[i-1][j-1][k]-S[i-1][j][k-1]-S[i][j-1][k-1]+S[i-1][j-1][k-1]);
		}
	}
	
	int z = 1<<28, zi0, zj0, zk0, zf, zc;
	for(int i0 = 1; i0 < 55; ++i0) {
		for(int j0 = 1; j0 < 55; ++j0) {
			for(int k0 = 1; k0 < 55; ++k0) {
				for(int f = 1; f < 55; ++f) {
					int i1 = max(1, i0-f),
						j1 = max(1, j0-f),
						k1 = max(1, k0-f),
						c = S[i0][j0][k0]-(S[i1][j0][k0]+S[i0][j1][k0]+S[i0][j0][k1]-S[i1][j1][k0]-S[i1][j0][k1]-S[i0][j1][k1]+S[i1][j1][k1]);
					if(c >= K && f-1 < z) {
						z = f-1;
						zi0 = i0, zj0 = j0, zk0 = k0, zf = f, zc = c;
					}
				}
			}
		}
	}
	
	printf("%d\n", z);
	for(int i = 0; i < P.size() && K; ++i) if(min(zi0-P[i].first, min(zj0-P[i].second, zk0-P[i].third)) >= 0 && max(zi0-P[i].first, max(zj0-P[i].second, zk0-P[i].third)) < zf) {
		printf("%d %d %d\n", P[i].first-1, P[i].second-1, P[i].third-1);
		--K;
	}
	return 0;
}
