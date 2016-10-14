// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/5902
// Movie collection
// trees
// 
// 
// AC (2012-06-08 15:07:12)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

typedef long long vlong;

class Fwtree {
	vlong t[100005*2];
	
public:
	Fwtree() {
		clear();
	}
	
	void clear() {
		CLR(t);
	}
	
	void add(int i, vlong v) {
		while(i <= 100005*2-2)
			t[i] += v, i += i & -i;
	}
	
	vlong sum(int i) {
		vlong r = 0;
		while(i > 0)
			r += t[i], i -= i & -i;
		return r;
	}
};

Fwtree F;
int P[100005], t;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		F.clear();
		for(int i = 1; i <= n; ++i) {
			P[i] = 100005+i;
			F.add(P[i], 1);
		}
		t = 100005-1;
		while(m--) {
			int a;
			scanf("%d", &a);
			F.add(P[a], -1);
			printf("%d", F.sum(P[a]));
			P[a] = t--;
			F.add(P[a], 1);
			if(m > 0)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
