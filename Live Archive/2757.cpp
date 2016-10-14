// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/2757
// Supermarket
// greedy
// 
// 
// AC (2012-07-16 05:02:24)

#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>

#define SET(c, v) memset(c, v, sizeof(c))
#define ALL(c) c.begin(), c.end()

using namespace std;

struct Prod {
    int p, d;

    bool operator<(const Prod &r) const {
        return p < r.p || p == r.p && d < r.d;
    }
};

int M[10002];

int main() {
    int n;
    while(cin >> n) {
        vector<Prod> X;
        for(int i = 0; i < n; ++i) {
            Prod x;
            cin >> x.p >> x.d;
            X.push_back(x);
        }
        sort(ALL(X));
        SET(M, 0);
        for(int i = X.size()-1; i >= 0; --i) {
            for(int j = 0; X[i].d-j > 0; ++j) if(M[X[i].d-j] < X[i].p) {
                M[X[i].d-j] = X[i].p;
                break;
            }
        }
        int R = 0;
        for(int i = 0; i < 10002; ++i)
            R += M[i];
        cout << R << endl;
    }
    return 0;
}
