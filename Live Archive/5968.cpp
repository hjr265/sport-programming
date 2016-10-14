// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/5968
// My Visit to Spring Secret
// implementation
// 
// 
// AC (2012-09-11 04:28:00)

#include <iostream>
#include <string>

using namespace std;

int main() {
	int T, no = 1;
	cin >> T;
	while(T--) {
		string S;
		cin >> S;
		int Y = 0, Z = 0;
		for(int i = 0; i < S.size()-1; ++i) if(S[i] == 'S')
			Y += S[i+1] == 'S', Z += S[i+1] != 'S';
		cout << "Case " << no++ << ": " << Y << " / " << Z << endl;
	}
	return 0;
}
