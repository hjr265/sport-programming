// In the name of Allah, Most Gracious, Most Merciful

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int L;
char P[10000005];
int F[10000005];

void kmp() {
	bool Z = false;
	F[0] = -1;
	F[1] = 0;
	int k = -1;
	for(int i = 2, j = 0; P[i]; ) {
		if(P[i-1] == P[j])
			F[i++] = ++j;
		else if(j > 0)
			j = F[j];
		else
			F[i++] = 0;
		if(Z && F[i-1] == L && i != k) {
			printf("%d\n", i-L*2-2);
			k = i;
		}
		if(P[i-1] == '!')
			Z = true;
	}
}

int main() {
	int i = 0;
	while(scanf("%d\n", &L) == 1) {
		if(i > 0)
			printf("\n");
		++i;
		scanf("%s", P);
		P[L] = '!';
		scanf("%s", P+L+1);
		strcat(P, "$");
		kmp();
	}
	return 0;
}
