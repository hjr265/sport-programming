// In the name of Allah, Most Gracious, Most Merciful

// UVA/11643
// Knight Tour
// dp
// 
// 
// AC (2012-09-10 14:28:41)

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <utility>

#define SET(c, v) memset(c, v, sizeof(c))

using namespace std;

typedef long long vlong;

int N, K;
pair<int, int> X[18];
int D[18][18];

int dist(int i, int j) {
	if(X[i].first == 1 && X[i].second == 1 && X[j].first == 2 && X[j].second == 2 ||
		X[i].first == N && X[i].second == N && X[j].first == N-1 && X[j].second == N-1 ||
		X[i].first == N && X[i].second == 1 && X[j].first == N-1 && X[j].second == 2 ||
		X[i].first == 1 && X[i].second == N && X[j].first == 2 && X[j].second == N-1 || 
		X[j].first == 1 && X[j].second == 1 && X[i].first == 2 && X[i].second == 2 ||
		X[j].first == N && X[j].second == N && X[i].first == N-1 && X[i].second == N-1 ||
		X[j].first == N && X[j].second == 1 && X[i].first == N-1 && X[i].second == 2 ||
		X[j].first == 1 && X[j].second == N && X[i].first == 2 && X[i].second == N-1)
		return 4;
		
	int ir = X[i].first,
		ic = X[i].second,
		jr = X[j].first,
		jc = X[j].second;
    int a = abs(ir-jr),
    	b = abs(ic-jc);
    if(a < b)
    	swap(a,b);
    if(a==1 && b==0)
    	return 3;
    if(a==2 && b==2)
    	return 4;
    int z = max((a+1)/2, (a+b+2)/3);
    if((z%2) != (a+b)%2)
    	z++;
    return z;
}

vlong M[18][(1<<16)+2];

vlong dp(int x, int i) {
	if(x == (1<<K)-1)
		return D[i][0];
	vlong &r = M[i][x];
	if(r == -1) {
		r = 1LL<<60;
		for(int j = 0; j < K; ++j) if(i != j && (x&(1<<j)) == 0)
			r = min(r, dp(x|(1<<j), j)+D[i][j]);
	}
	return r;
}

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &N, &K);
		for(int i = 0; i < K; ++i)
			scanf("%d %d", &X[i].first, &X[i].second);
		for(int i = 0; i < K; ++i) {
			for(int j = 0; j < i; ++j)
				D[i][j] = D[j][i] = dist(i, j);
		}
		SET(M, -1);
		cout << "Case " << no++ << ": " << dp(1<<0, 0) << '\n';
	}
	return 0;
}
