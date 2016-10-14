// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1212
// Double Ended Queue
// data structures
// 
// 
// AC (2011-07-27 10:18:35)

#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))
#define ALL(c) c.begin(), c.end()
#define SLC(c, n) c, c+n

using namespace std;

typedef unsigned int uint;
typedef long long vlong;
typedef unsigned long long uvlong;

const double inf = 1e20;
const double pi = acos(-1.0);

int main() {
	int T, no = 1;
	cin >> T;
	while(T--) {
		cout << "Case " << no++ << ":" << '\n';
		int n, m;
		cin >> n >> m;
		int q[n*2+6];
		int i = n*2+2, j = i+1;
		while(m--) {
			string c;
			cin >> c;
			int x;
			if(c == "pushLeft" || c == "pushRight") {
				cin >> x;
				if(j-i-1 == n) {
					cout << "The queue is full" << endl;
					continue;
				}
			} else {
				if(j == i+1) {
					cout << "The queue is empty" << endl;
					continue;
				}
			}
			if(c == "pushLeft") {
				q[i] = x;
				i -= 1;
				cout << "Pushed in left: " << x << endl;
			} else if(c == "pushRight") {
				q[j] = x;
				j += 1;
				cout << "Pushed in right: " << x << endl;
			} else if(c == "popLeft") {
				i += 1;
				cout << "Popped from left: " << q[i] << endl;
			} else if(c == "popRight") {
				j -= 1;
				cout << "Popped from right: " << q[j] << endl;
			}
		}
	}
	return 0;
}
