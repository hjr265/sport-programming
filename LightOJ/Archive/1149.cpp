// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1149
// Factors and Multiples
// graph matchings
// 
// 
// AC (2012-02-03 10:53:49)

#include <cstdio>
#include <cstring>
#include <vector>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

vector<int> A;
vector<int> B;

int L[102];
int R[102];
bool c[102];

bool bpm(int u) {
	if(c[u])
		return false;
	c[u] = true;
	for(int v = 0, l = B.size(); v < l; ++v) if(B[v]%A[u] == 0) {
		if(R[v] == -1 || bpm(R[v])) {
			L[u] = v;
			R[v] = u;
			return true;
		}
	}
	return false;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d", &n);
		A.clear();
		while(n--) {
			int x;
			scanf("%d", &x);
			A.push_back(x);
		}
		scanf("%d", &m);
		B.clear();
		while(m--) {
			int x;
			scanf("%d", &x);
			B.push_back(x);
		}
		SET(L);
		SET(R);
		bool d;
		do {
			d = true;
			CLR(c);
			for(int u = 0; u < A.size(); ++u) if(L[u] == -1 && bpm(u))
				d = false;
		} while(!d);
		int r = 0;
		for(int u = 0; u < A.size(); ++u) if(L[u] != -1)
			++r;
		printf("Case %d: %d\n", no++, r);
	}
	return 0;
}
