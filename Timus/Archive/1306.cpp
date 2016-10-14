// In the name of Allah, Most Gracious, Most Merciful

// Timus/1306
// Sequence Median
// data structures
// 
// 
// AC (18:48:28 15 Oct 2012)

#include <cstdio>
#include <queue>

using namespace std;

typedef unsigned int uint;
typedef long long vlong;

int main() {
	int N;
	scanf("%d", &N);
	priority_queue<uint> P;
	for(int i = 0; i < N/2+1; ++i) {
		uint X;
		scanf("%u", &X);
		P.push(X);
	}
	
	for(int i = N/2+1; i < N; ++i) {
		uint X;
		scanf("%u", &X);
		if(X < P.top()) {
			P.pop();
			P.push(X);
		}
	}
	
	if(N%2) {
		printf("%u\n", P.top());
	} else {
		vlong R = P.top();
		P.pop();
		R += P.top();
		if(R%2)
			printf("%u.5\n", R/2);
		else
			printf("%u\n", R/2);
	}
	return 0;
}
