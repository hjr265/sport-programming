// In the name of Allah, Most Gracious, Most Merciful

// Timus/1104
// Don’t Ask Woman about Her Age
// number theory
// 
// 
// AC (20:48:57 29 Apr 2012)

#include <cstdio>
#include <algorithm>

using namespace std;

char S[1000005];

int main() {
	scanf("%s", S);
	for(int k = 2; k <= 37; ++k) {
		if(k == 37) {
			printf("No solution.\n");
			break;
		}
		int t = 0;
		for(int i = 0; S[i]; ++i) {
			int d = S[i] >= '0' && S[i] <= '9' ? S[i]-'0' : S[i]-'A'+10;
			t = (t*k+d)%(k-1);
			if(d >= k) {
				t = -1;
				break;
			}
		}
		if(t == 0) {
			printf("%d\n", k);
			break;
		}
	}
	return 0;
}
