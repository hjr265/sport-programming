// In the name of Allah, Most Gracious, Most Merciful

// Timus/1613
// For Fans of Statistics
// binary search, data structures
// 
// 
// AC (19:05:52 15 Oct 2012)

#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

#define ALL(c) c.begin(), c.end()

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	map<int, vector<int> > M;
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		M[x].push_back(i);
	}
	
	int q;
	scanf("%d", &q);
	while(q--) {
		int l, r, x;
		scanf("%d %d %d", &l, &r, &x);
		vector<int> &v = M[x];
		printf("%d", (upper_bound(ALL(v), r-1)-v.begin())-(lower_bound(ALL(v), l-1)-v.begin()) > 0);
	}
	printf("\n");
	return 0;
}
