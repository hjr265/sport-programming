// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1249
// Chocolate Thief
// implementation
// 
// 
// AC (2011-07-27 09:24:33)

#include <iostream>
#include <string>

using namespace std;

int main() {
	int T, no = 1;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		string na, nb;
		int va = 1234567890, vb = -1234567890;
		while(n--) {
			string s;
			cin >> s;
			int x, y, z;
			cin >> x >> y >> z;
			int v = x*y*z;
			if(v < va)
				va = v, na = s;
			if(v > vb)
				vb = v, nb = s;
		}
		cout << "Case " << no++ << ": ";
		if(va == vb)
			cout << "no thief" << '\n';
		else
			cout << nb << " took chocolate from " << na << '\n';
	}
	return 0;
}
