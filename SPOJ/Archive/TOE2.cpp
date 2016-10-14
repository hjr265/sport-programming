// In the name of Allah, Most Gracious, Most Merciful

// SPOJ/TOE2
// Tic-Tac-Toe (II)
// dfs and similar
// 
// 
// AC (2012-11-25 11:44:05)

#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

bool isover(int u) {
	int X[3][3], t = 0;
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(u%3 == 0)
				++t;
			X[i][j] = u%3, u /= 3;
		}
	}
	if(t == 0)
		return true;
	for(int i = 0; i < 3; ++i) if(X[i][0] != 0 && X[i][0] == X[i][1] && X[i][1] == X[i][2] || X[0][i] != 0 && X[0][i] == X[1][i] && X[1][i] == X[2][i])
		return true;
	return (X[0][0] == X[1][1] && X[1][1] == X[2][2] || X[0][2] == X[1][1] && X[1][1] == X[2][0]) && X[1][1] != 0;
}

bool C[20000];
set<int> S;

void search(int u, int x) {
	if(C[u])
		return;
	C[u] = true;
	if(isover(u)) {
		S.insert(u);
		return;
	}
	for(int i = 0, g = 1; i < 9; ++i, g *= 3) if((u/g)%3 == 0)
		search((((u/g)/3)*3+x)*g+u%g, 3-x);
}

int main() {
	search(0, 1);
	char B[10];
	while(scanf("%s", B) && B[0] != 'e') {
		int u = 0;
		for(int i = 0; B[i]; ++i) {
			u *= 3;
			switch(B[i]) {
			case 'X':
				u += 1;
				break;
			case 'O':
				u += 2;
				break;
			}
		}
		printf("%s\n", S.count(u) ? "valid" : "invalid");
	}
	return 0;
}
