// In the name of Allah, Most Gracious, Most Merciful

// Timus/1723
// Sandro's Book
// strings
// 
// 
// AC (19:00:01 29 Apr 2012)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

char S[55];
int C[30];

int main() {
	scanf("%s", S);
	CLR(C);
	int t = 0;
	for(int i = 0; S[i]; ++i)
		t = max(t, ++C[S[i]-'a']);
	for(int i = 0; i < 26; ++i) if(C[i] == t) {
		printf("%c\n", 'a'+i);
		break;
	}
	return 0;
}
