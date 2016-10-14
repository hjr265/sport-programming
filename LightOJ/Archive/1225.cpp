// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1225
// Palindromic Numbers (II)
// implementation
// 
// 
// AC (2011-07-27 10:28:43)

#include <iostream>
#include <string>

using namespace std;

bool ispal(const string &n, int i, int j) {
	if(i >= j)
		return true;
	if(n[i] == n[j])
		return ispal(n, i+1, j-1);
	return false;
}

int main() {
	int T, no = 1;
	cin >> T;
	while(T--) {
		string n;
		cin >> n;
		cout << "Case " << no++ << ": " << (ispal(n, 0, n.size()-1) ? "Yes" : "No") << '\n';
	}
	return 0;
}
