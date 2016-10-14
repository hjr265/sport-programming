// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1113
// Discover the Web
// data structures
// 
// 
// AC (2011-07-31 12:01:20)

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	int T, no = 1;
	cin >> T;
	while(T--) {
		cout << "Case " << no++ << ":" << endl;
		string c;
		stack<string> b, f;
		string p = "http://www.lightoj.com/";
		while(cin >> c && c != "QUIT") {
			if(c == "BACK") {
				if(!b.empty()) {
					f.push(p);
					p = b.top();
					b.pop();
					cout << p << endl;
				} else {
					cout << "Ignored" << endl;
				}
			} else if(c == "FORWARD") {
				if(!f.empty()) {
					b.push(p);
					p = f.top();
					f.pop();
					cout << p << endl;
				} else {
					cout << "Ignored" << endl;
				}
			} else {
				string u;
				cin >> u;
				b.push(p);
				while(!f.empty())
					f.pop();
				p = u;
				cout << u << endl;
			}
		}
	}
	return 0;
}
