// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1166
// Old Sorting
// greedy
// 
// 
// AC (2011-09-14 13:18:08)

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int a[n];
		for(int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		int z = 0;
		for(int i = 0; i < n; ) {
			if(i == a[i]-1)
				++i;
			else
				++z, swap(a[i], a[a[i]-1]);
		}
		printf("Case %d: %d\n", no++, z);
	}
}
