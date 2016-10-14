// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1114
// Easily Readable
// combinatorics
// 
// 
// AC (2012-05-04 13:49:55)

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

typedef long long vlong;

int main() {
	int T, no = 1;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		map<string, vlong> M;
		while(n--) {
			string w;
			cin >> w;
			if(w.size() > 1)
				sort(w.begin()+1, w.end()-1);
			++M[w];
		}
		int m;
		cin >> m;
		scanf("\n");
		cout << "Case " << no++ << ":\n";
		while(m--) {
			vlong r = 1;
			string s;
			getline(cin, s);
			stringstream t(s);
			string w;
			while(t >> w && r) {
				if(w.size() > 1)
					sort(w.begin()+1, w.end()-1);
				r *= M[w];
			}
			cout << r << '\n';
		}
	}
	return 0;
}
