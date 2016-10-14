// In the name of Allah, Most Gracious, Most Merciful

// Timus/1060
// Flip Game
// games
// 
// 
// AC (11:45:47 30 May 2012)

#include <cstdio>
#include <algorithm>

using namespace std;

int x = 0;
int r = 9999999;

void flip(int i, int j) {
	if(i < 0 || i >= 4 || j < 0 || j >= 4)
		return;
	x ^= 1<<(i*4+j);
}

void solve(int i, int m) {
	if(m > r)
		return;
	if(x == 0 || x == (1<<16)-1) {
		r = min(r, m);
		return;
	}
	if(i == 16)
		return;
	solve(i+1, m);
	flip(i/4, i%4);
	flip(i/4-1, i%4);
	flip(i/4, i%4+1);
	flip(i/4+1, i%4);
	flip(i/4, i%4-1);
	solve(i+1, m+1);
	flip(i/4, i%4-1);
	flip(i/4+1, i%4);
	flip(i/4, i%4+1);
	flip(i/4-1, i%4);
	flip(i/4, i%4);
}

int main() {
	for(int i = 0; i < 4; ++i) {
		char S[5];
		scanf("%s", S);
		for(int j = 0; j < 4; ++j)
			x <<= 1, x |= S[j] == 'w';
	}
	solve(0, 0);
	if(r == 9999999)
		printf("Impossible\n");
	else
		printf("%d\n", r);
	return 0;
}
