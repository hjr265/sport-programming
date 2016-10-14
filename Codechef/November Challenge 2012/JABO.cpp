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

template<int N>
class Dsets {
	int p[N], r[N];
	
public:
	Dsets() {
		clear();
	}
	
	void clear() {
		for(int i = 0; i < N; ++i)
			p[i] = i;
		SET(r, 0);
	}
	
	int parent(int a) {
		if(p[a] != a)
			p[a] = parent(p[a]);
		return p[a];
	}
	
	void merge(int a, int b) {
		a = parent(a);
		b = parent(b);
		if(r[a] > r[b])
			p[b] = a;
		else
			p[a] = b;
		if(r[a] == r[b])
			++r[b];
	}
};

Dsets<1265100> DS;
int CN[1265100];

int fiftytwo2ten(char A[]) {
	int r = 0;
	for(int i = 0; i < 2; ++i) {
		r *= 52;
		if(A[i] >= 'A' && A[i] <= 'Z')
			r += A[i]-'A';
		else
			r += A[i]-'a'+26;
	}
	return r;
}

int main() {
	int N, R, C;
	scanf("%d %d %d", &N, &R, &C);
	while(N--) {
		char S[20];
		scanf("%s", S);
		int Ax, Ay, Bx, By, A, B;
		switch(S[0]) {
		case 'W':
			Ax = fiftytwo2ten(S+1), Ay = fiftytwo2ten(S+3), Bx = fiftytwo2ten(S+5), By = fiftytwo2ten(S+7);
			Ay = (Ay-1)/5+1;
			By = (By-1)/5+1;
			A = Ax*R+Ay;
			B = Bx*R+By;
			
			A = DS.parent(A);
			B = DS.parent(B);
			if(A == B)
				break;
			DS.merge(A, B);
			CN[DS.parent(A)] = CN[A]+CN[B];
			break;
		case 'V':
			Ax = fiftytwo2ten(S+1), Ay = fiftytwo2ten(S+3);
			Ay = (Ay-1)/5+1;
			A = Ax*R+Ay;
			
			++CN[DS.parent(A)];
			break;
		case 'R':
			Ax = fiftytwo2ten(S+1), Ay = fiftytwo2ten(S+3);
			Ay = (Ay-1)/5+1;
			A = Ax*R+Ay;
			
			--CN[DS.parent(A)];
			break;
		case 'L':
			Ax = fiftytwo2ten(S+1), Ay = fiftytwo2ten(S+3), Bx = fiftytwo2ten(S+5), By = fiftytwo2ten(S+7);
			Ay = (Ay-1)/5+1;
			By = (By-1)/5+1;
			A = Ax*R+Ay;
			B = Bx*R+By;
			
			A = DS.parent(A);
			B = DS.parent(B);
			
			cout << (CN[A] > 0 && CN[B] == 0 || CN[B] > 0 && CN[A] == 0 ? "ON" : "OFF") << '\n';
			break;
		}
	}
	return 0;
}
