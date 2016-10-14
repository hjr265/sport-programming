// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/2759
// Common Subsequence
// dp
// 
// 
// AC (2012-07-16 05:03:43)

#include <cstring>
#include <iostream>

#define SET(c, v) memset(c, v, sizeof(c))

using namespace std;

string X, Y;
int D[208][208];

int dp(int i, int j) {
    if(i < 0 || j < 0)
        return 0;
    int &r = D[i][j];
    if(r == -1) {
        if(X[i] == Y[j])
            r = dp(i-1, j-1)+1;
        else
            r = max(dp(i-1, j), dp(i, j-1));
    }
    return r;
}

int main() {
    while(cin >> X >> Y) {
        SET(D, -1);
        cout << dp(X.size()-1, Y.size()-1) << endl;
    }
    return 0;
}
