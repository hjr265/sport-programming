// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1229
// Treblecross
// games
// 
// 
// AC (2012-02-03 21:52:44)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))
#define ALL(c) c.begin(), c.end()

using namespace std;

int g[2][2][202];

int nimber(int l, int r, int w) {
	if(w <= 1)
		return 0;
	if(r < l)
		return nimber(r, l, w);
	int &z = g[l][r][w];
	if(z == -1) {
		set<int> s;
		for(int i = (l==1)*2; i < w-(r==1)*2; ++i)
			s.insert(nimber(l, 1, i)^nimber(1, r, w-i-1));
		z = 0;
		while(s.count(z))
			++z;
	}
	return z;
}

int hash(char c) {
	return c == 'X';
}

char S[205];

int main() {
	SET(g);
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", S+1);
		int N = strlen(S+1)+1;
		vector<int> z;
		for(int i = 1; i < N; ++i) if(S[i] == 'X') {
			for(int j = i-2; j < i+3; ++j) if(j >= 1 && j < N && i != j && S[j] == 'X') {
				switch(i-j) {
				case 2:
					z.push_back(j+1);
					break;
				case 1:
					if(j-1 >= 1)
						z.push_back(j-1);
					if(i+1 <= N)
						z.push_back(i+1);
					break;
				case -1:
					if(i-1 >= 1)
						z.push_back(i-1);
					if(j+1 <= N)
						z.push_back(j+1);
					break;
				case -2:
					z.push_back(i+1);
					break;
				}
			}
		}
		if(z.size() == 0) {
			int r = 0;
			for(int i = 0; i < N; ) {
				for(int j = i+1; j <= N; ++j) if(S[j] != '.') {
					r ^= nimber(hash(S[i]), hash(S[j]), j-i-1);
					i = j;
					break;
				}
			}
			if(r != 0) {
				for(int i = 0; i < N; ) {
					for(int j = i+1; j <= N; ++j) if(S[j] != '.') {
						r ^= nimber(hash(S[i]), hash(S[j]), j-i-1);
						for(int k = i+1+(hash(S[i])==1)*2; k < j-(hash(S[j])==1)*2; ++k) if((r^nimber(hash(S[i]), 1, k-i-1)^nimber(1, hash(S[j]), j-k-1)) == 0) {
							z.push_back(k);
						}
						r ^= nimber(hash(S[i]), hash(S[j]), j-i-1);
						i = j;
						break;
					}
				}
			}
		}
		if(z.size() == 0)
			z.push_back(0);
		sort(ALL(z));
		printf("Case %d:", no++);
		for(int i = 0; i < z.size(); ++i) if(z[i] == 0 || (i == 0 || z[i] != z[i-1]) && z[i] >= 1 && z[i] < N)
			printf(" %d", z[i]);
		printf("\n");
	}
	return 0;
}
