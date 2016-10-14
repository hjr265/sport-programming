// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1224
// DNA Prefix
// trees
// 
// 
// AC (2012-05-09 12:11:38)

#include <cstdio>
#include <cstring>
#include <algorithm>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

typedef long long vlong;

class Trie {
	struct Node {
		int C[4], w, d;
	};
	
	Node T[1000005];
	int n;

public:
	Trie() {
		clear();
	}
	
	void clear() {
		CLR(T);
		n = 2;
	}
	
	void add(char S[]) {
		int p = 1;
		for(int i = 0; S[i]; ++i) {
			int x = T[p].C[S[i]-1];
			if(x == 0)
				x = n++;
			++T[x].w;
			T[x].d = i+1;
			T[p].C[S[i]-1] = x;
			p = x;
		}
	}
	
	vlong score() {
		vlong r = 0;
		for(int i = 1; i < n; ++i)
			r = max(r, (vlong)T[i].w*T[i].d);
		return r;
	}
};

Trie X;
char S[55];

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		X.clear();
		while(n--) {
			scanf("%s", S);
			for(int i = 0; S[i]; ++i) switch(S[i]) {
			case 'A':
				S[i] = 1;
				break;
			case 'C':
				S[i] = 2;
				break;
			case 'G':
				S[i] = 3;
				break;
			case 'T':
				S[i] = 4;
				break;
			}
			X.add(S);
		}
		printf("Case %d: %lld\n", no++, X.score());
	}
	return 0;
}
