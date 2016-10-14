// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1344
// Aladdin and the Game of Bracelets
// dp, *games
// 
// 
// AC (2012-01-29 22:32:12)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))
#define ALL(c) c.begin(), c.end()

using namespace std;

vector<int> B[52];
int N[52][52][52];

int nimber(int i, int j, int k) {
	if(j >= k)
		return 0;
	int &r = N[i][j][k];
	if(r == -1) {
		set<int> s;
		for(int l = j; l < k; ++l) {
			int w = B[i][l];
			int x = 0;
			for(int m = j, n = j; n <= k; ++n) {
				if(n == k || B[i][n] >= w) {
					x ^= nimber(i, m, n);
					m = n+1;
				}
			}
			s.insert(x);
		}
		r = 0;
		while(s.count(r))
			++r;
	}
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			B[i].clear();
			int k;
			scanf("%d", &k);
			while(k--) {
				int w;
				scanf("%d", &w);
				B[i].push_back(w);
			}
		}
		SET(N);
		int r = 0;
		for(int i = 0; i < n; ++i)
			r ^= nimber(i, 0, B[i].size());
		vector<pair<int, int> > z;
		for(int i = 0; i < n; ++i) {
			int x = r;
			x ^= nimber(i, 0, B[i].size());
			for(int j = 0; j < B[i].size(); ++j) {
				int w = B[i][j];
				int y = 0;
				for(int m = 0, n = 0, l = B[i].size(); n <= l; ++n) {
					if(n == l || B[i][n] >= w) {
						y ^= nimber(i, m, n);
						m = n+1;
					}
				}
				if((x^y) == 0)
					z.push_back(pair<int, int>(i+1, w));
			}
			x ^= nimber(i, 0, B[i].size());
		}
		sort(ALL(z));
		printf("Case %d: ", no++);
		if(r == 0) {
			printf("Genie\n");
		} else {
			printf("Aladdin\n");
			for(int i = 0; i < z.size(); ++i) {
				if(i > 0 && z[i].first == z[i-1].first && z[i].second == z[i-1].second)
					continue;
				printf("(%d %d)", z[i].first, z[i].second);
			}
			printf("\n");
		}
	}
	return 0;
}
