// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1425
// The Monkey and the Oiled Bamboo
// greedy
// 
// 
// AC (2012-03-05 23:59:04)

#include <cstdio>
#include <algorithm>
#include <vector>

#define ALL(c) c.begin(), c.end()

using namespace std;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int q = 0;
		vector<int> z;
		while(n--) {
			int r;
			scanf("%d", &r);
			z.push_back(r-q);
			q = r;
		}
		int m = *max_element(ALL(z));
		int r = m;
		for(int i = 0; i < z.size(); ++i) {
			if(z[i] == m) {
				--m;
			} else if(z[i] > m)
				++r, m = r;
		}
		printf("Case %d: %d\n", no++, r);
	}
	return 0;
}
