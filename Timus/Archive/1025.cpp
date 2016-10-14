// In the name of Allah, Most Gracious, Most Merciful

// Timus/1025
// Democracy in Danger
// implementation
// 
// 
// AC (13:43:26 28 Apr 2012)

#include <cstdio>
#include <algorithm>
#include <vector>

#define ALL(c) c.begin(), c.end()

using namespace std;

int main() {
	int K;
	scanf("%d", &K);
	vector<int> V;
	while(K--) {
		int n;
		scanf("%d", &n);
		V.push_back(n);
	}
	sort(ALL(V));
	int r = 0;
	for(int i = 0; i <= V.size()/2; ++i)
		r += (V[i]+1)/2;
	printf("%d\n", r);
	return 0;
}
