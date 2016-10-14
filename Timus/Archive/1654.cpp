// In the name of Allah, Most Gracious, Most Merciful

// Timus/1654
// Cipher Message
// data structures
// 
// 
// AC (18:04:48 15 Oct 2012)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <string>

#define ALL(c) c.begin(), c.end()

using namespace std;

char S[200005];

int main() {
	scanf("%s", S);
	
	stack<char> K;
	for(int i = 0; S[i]; ++i) {
		if(K.empty() || K.top() != S[i])
			K.push(S[i]);
		else if(!K.empty())
			K.pop();
	}
	
	string R;
	while(!K.empty()) {
		R += K.top();
		K.pop();
	}
	reverse(ALL(R));
	
	printf("%s\n", R.c_str());
	return 0;
}
