// In the name of Allah, Most Gracious, Most Merciful

// Codeforces/Codeforces Round #141 (Div. 2)/A
// Is your horseshoe on the other hoof?
// implementation
// http://codeforces.com/contest/228/problem/A
// 
// AC (Nov 2, 2012 5:37:45 PM)

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

int main() {
    int s[4];
    for(int i = 0; i < 4; ++i)
        cin >> s[i];
    sort(SLC(s, 4));
    
    int z = 0;
    for(int i = 1; i < 4; ++i) if(s[i] == s[i-1])
        ++z;
    cout << z << endl;
    return 0;
}
