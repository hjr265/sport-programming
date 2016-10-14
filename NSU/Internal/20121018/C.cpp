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

struct Freeseg {
	Freeseg *left, *right;
	int start, end;
	int mingy;
	int freespace;
	
	Freeseg(int start_, int end_) : left(NULL), right(NULL), start(start_), end(end_) {
		mingy = 0;
		freespace = end_-start_+1;
	}
	
	bool contains(int i) {
		return i >= start && i <= end;
	}
	
	bool isempty() {
		return left == NULL && right == NULL;
	}
	
	int findspot() {
		if(isempty())
			return (start+end+1)/2;
		
		if(left->freespace > right->freespace)
			return left->findspot();
		return right->findspot();
	}
	
	void split(int i) {
		if(!isempty()) {
			if(left->contains(i))
				left->split(i);
			else
				right->split(i);
			mingy = left->mingy+right->mingy+1;
		} else {
			left = new Freeseg(start, i-1);
			right = new Freeseg(i+1, end);
			mingy = 1;
		}		
		freespace = max(left->freespace, right->freespace);
	}
	
	Freeseg *merge(int i) {
		if(left->contains(i)) {
			left = left->merge(i);
			mingy = left->mingy+right->mingy+1;
			freespace = max(left->freespace, right->freespace);
		} else if(right->contains(i)) {
			right = right->merge(i);
			mingy = left->mingy+right->mingy+1;
			freespace = max(left->freespace, right->freespace);
		} else {
			if(!left->isempty() && !right->isempty()) {
				
			} else if(!left->isempty()) {
				
				mingy = 0;
				freespace = end-start+1;
				return left;
			} else if(!right->isempty()) {
				
				mingy = 0;
				freespace = end-start+1;
				return right;
			} else {
				delete left;
				left = NULL;
				delete right;
				right = NULL;
				mingy = 0;
				freespace = end-start+1;
			}
		}
		return this;
	}
};

int main() {
	Freeseg *X = new Freeseg(1, 10);
	cout << X->findspot() << " " << X->mingy << endl;
	X->split(X->findspot());
	cout << X->findspot() << " " << X->mingy << endl;
	X->split(X->findspot());
	cout << X->findspot() << " " << X->mingy << endl;
	X->split(X->findspot());
	cout << X->findspot() << " " << X->mingy << endl;
	X->split(X->findspot());
	cout << X->findspot() << " " << X->mingy << endl;
	X = X->merge(8);
	cout << X->findspot() << " " << X->mingy << endl;
	X = X->merge(6);
	cout << X->findspot() << " " << X->mingy << endl;
	X = X->merge(3);
	cout << X->findspot() << " " << X->mingy << endl;
	X = X->merge(9);
	cout << X->findspot() << " " << X->mingy << endl;
	
	/*int n, q;
	scanf("%d %d", &n, &q);
	while(q--) {
		Query Qi;
		scanf("%d", &Qi.C);
		if(C == 0) {
			scanf("%d %d", &Qi.i, &Qi.j);
			IX.push_back(Qi.i);
			IX.push_back(Qi.j);
		} else {
		}
	}*/
	return 0;
}
