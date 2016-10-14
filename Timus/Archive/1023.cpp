// In the name of Allah, Most Gracious, Most Merciful

// Timus/1023
// Buttons
// games
// 
// 
// AC (11:10:47 29 Apr 2012)

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long vlong;

vlong maxdiv(vlong K) {
	if(K <= 2)
		return 0;
	for(vlong i = 3; i < K; ++i) if(K%i == 0)
		return i-1;
	return K-1;
}

int main() {
	vlong K;
	scanf("%lld", &K);
	printf("%lld\n", maxdiv(K));
	return 0;
}
