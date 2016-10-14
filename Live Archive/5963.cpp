// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/5963
// Confusion in the Problem Set
// implementation
// 
// 
// AC (2012-09-11 04:55:07)

#include <cstring>
#include <iostream>

#define SET(c, v) memset(c, v, sizeof(c))

using namespace std;

bool P[10002];

int main() {
	int T, no = 1;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		bool f = true;
		SET(P, 0);
		for(int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			if(x >= 0 && x < n && !P[x])
				P[x] = true;
			else if(n-x-1 >= 0 && n-x-1 < n && !P[n-x-1])
				P[n-x-1] = true;
			else
				f = false;
		}
		cout << "Case " << no++ << ": ";
		if(f)
			cout << "yes";
		else
			cout << "no";
		cout << endl;
	}
	return 0;
}
