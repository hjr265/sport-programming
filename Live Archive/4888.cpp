// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/4888
// Railroad
// dp
// 
// 
// AC (2011-08-09 09:51:09)

#include <cstdio>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))

using namespace std;

int t1[1005];
int t2[1005];
int t3[2005];
char mo[1005][1005];

bool take(int N1, int N2, int i, int j, int k) {
	if(k == N1+N2)
		return 1;
	if(i == N1 && j == N2)
		return 0;
	char &m = mo[i][j];
	if(m == -1) {
		m = 0;
		if(i < N1 && t1[i] == t3[k])
			m = m || take(N1, N2, i+1, j, k+1);
		if(j < N2 && t2[j] == t3[k])
			m = m || take(N1, N2, i, j+1, k+1);
	}
	return m;
}

int main() {
	int N1, N2;
	while(scanf("%d %d", &N1, &N2) == 2 && (N1 != 0 || N2 != 0)) {
		for(int i = 0; i < N1; ++i)
			scanf("%d", &t1[i]);
		for(int i = 0; i < N2; ++i)
			scanf("%d", &t2[i]);
		for(int i = 0; i < N1+N2; ++i)
			scanf("%d", &t3[i]);
		SET(mo);
		if(take(N1, N2, 0, 0, 0))
			printf("possible\n");
		else
			printf("not possible\n");
	}
	return 0;
}
