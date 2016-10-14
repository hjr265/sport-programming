// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1199
// Partitioning Game
// games
// 
// 
// AC (2012-01-16 10:40:02)

#include <cstdio>
#include <cstring>
#include <set>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

int N[10002];

int nimber(int n) {
	if(n <= 2)
		return 0;
	if(N[n] == -1) {
		set<int> s;
		for(int i = 1; i <= n/2; ++i) if(i != n-i) {
			s.insert(nimber(i)^nimber(n-i));
		}
		int r = 0;
		while(s.count(r))
			++r;
		N[n] = r;
	}
	return N[n];
}

int main() {
	SET(N);
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int k;
		scanf("%d", &k);
		int r = 0;
		while(k--) {
			int x;
			scanf("%d", &x);
			r ^= nimber(x);
		}
		printf("Case %d: %s\n", no++, r ? "Alice" : "Bob");
	}
	return 0;
}
