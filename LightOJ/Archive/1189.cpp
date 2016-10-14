// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1189
// Sum of Factorials
// greedy
// 
// 
// AC (2011-10-11 12:34:52)

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long vlong;

vlong f[22];

int main() {
	f[0] = 1;
	for(vlong i = 1; i <= 20; ++i)
		f[i] = f[i-1]*i;
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		vlong n;
		scanf("%lld", &n);
		vector<int> r;
		for(int i = 20; i >= 0 && n > 0; --i) if(f[i] <= n) {
			n -= f[i];
			r.push_back(i);
		}
		sort(r.begin(), r.end());
		printf("Case %d: ", no++);
		if(n != 0) {
			printf("impossible");
		} else for(int i = 0, l = r.size(); i < l; ++i) {
			if(i == 0)
				printf("%d!", r[i]);
			else
				printf("+%d!", r[i]);
		}	
		printf("\n");
	}
}
