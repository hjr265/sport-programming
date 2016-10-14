// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1401
// No More Tic-tac-toe
// games
// 
// 
// AC (2012-02-03 20:57:12)

#include <cstdio>
#include <cstring>
#include <set>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

int g[3][3][102];

int nimber(int l, int r, int w) {
	int &z = g[l][r][w];
	if(z == -1) {
		set<int> s;
		for(int i = 0; i < w; ++i) {
			for(int j = 1; j < 3; ++j) if((i != 0 || j != l) && (i != w-1 || j != r))
				s.insert(nimber(l, j, i)^nimber(j, r, w-i-1));
		}
		z = 0;
		while(s.count(z))
			++z;
	}
	return z;
}

int hash(char c) {
	switch(c) {
	case 'X':
		return 1;
	case 'O':
		return 2;
	}
	return 0;
}

char S[105];

int main() {
	SET(g);
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", S+1);
		int N = strlen(S+1)+1;
		int r = 0;
		int c = 0;
		for(int i = 1; i < N; ++i) if(S[i] != '.')
			++c;
		for(int i = 0; i < N; ) {
			for(int j = i+1; j <= N; ++j) if(S[j] != '.') {
				r ^= nimber(hash(S[i]), hash(S[j]), j-i-1);
				i = j;
				break;
			}
		}
		printf("Case %d: %s\n", no++, (!!r)^(c%2) ? "Yes" : "No");
	}
	return 0;
}
