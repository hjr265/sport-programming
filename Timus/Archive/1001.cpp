// In the name of Allah, Most Gracious, Most Merciful

// Timus/1001
// Reverse Root
// implementation
// 
// 
// AC (13:22:24 28 Apr 2012)

#include <cstdio>
#include <cmath>
#include <stack>

using namespace std;

typedef long long vlong;

int main() {
	stack<vlong> S;
	vlong A;
	while(scanf("%lld", &A) == 1)
		S.push(A);
	while(!S.empty()) {
		printf("%0.4lf\n", sqrt((double)S.top()));
		S.pop();
	}
	return 0;
}
