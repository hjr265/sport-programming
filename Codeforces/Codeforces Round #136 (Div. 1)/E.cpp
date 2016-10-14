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

vlong n;
vlong k;
vlong A[100005];
vlong B[100005];
vlong C[100005];

vlong merge(vlong A[], vlong V[], vlong At[], vlong Vt[], vlong l, vlong m, vlong g) {
	vlong r = 0;
	vlong i = l, j = m, k = l;
	while(i <= m-1 && j <= g) {
		if(A[i] <= A[j]) {
			Vt[k] = V[i];
			At[k++] = A[i++];
		} else {
			Vt[k] = V[j]+(m-i);
			At[k++] = A[j++];
			r = r + (m - i);
		}
	}
	while(i <= m - 1)
		At[k++] = A[i++];
	while(j <= g)
		At[k++] = A[j++];
	for(i=l; i <= g; i++)
		A[i] = At[i];
	for(i=l; i <= g; i++)
		V[i] = Vt[i];
	return r;
}
  
vlong _count(vlong A[], vlong V[], vlong At[], vlong Vt[], vlong l, vlong g) {
	vlong m, r = 0;
	if (g > l) {
		m = (g+l)/2;
		r  = _count(A, V, At, Vt, l, m);
		r += _count(A, V, At, Vt, m+1, g);
		r += merge(A, V, At, Vt, l, m+1, g);
	}
	return r;
}

vlong count(vlong A[], vlong V[], vlong n) {
	vlong *At = new vlong[n];
	vlong *Vt = new vlong[n];
	vlong r = _count(A, V, At, Vt, 0, n-1);
	delete[] At;
	delete[] Vt;
	return r;
}

vlong nc2(vlong n) {
	return (n*(n-1))/2;
}

int main() {
	scanf("%I64d %I64d", &n, &k);
	for(vlong i = 0; i < n; ++i) {
		scanf("%I64d", &A[i]);
		B[i] = A[i];
	}
	C[0] = 0;
	count(B, C, n);
	//cout << count(B, C, n) << endl;
	for(vlong i = 0; i < n; ++i) 
		cout << A[i] << " ";
	cout << endl;
	for(vlong i = 0; i <= n; ++i) 
		cout << C[i] << " ";
	cout << endl;
	
	vlong z = 0;
	vlong p = 0;
	for(int i = 0, j = 0; i < n; ++i) {
		vlong x = p;
		while(j < n && x+C[j] <= k)
			x += C[j++];
		++j;
		cout << i << " " << j << " " << k << " " << (j-i-1) <<  endl;
		
		z += j-i-1;
		
		--j;
		
		p = x-C[i];
	}
	
	cout << z << endl;
	
	return 0;
}
