// In the name of Allah, Most Gracious, Most Merciful

// Timus/1180
// Stone Game
// games
// 
// 
// AC (14:09:27 29 Apr 2012)

#include <cstdio>

int main() {
	char N[255];
	scanf("%s", N);
	int t = 0;
	for(int i = 0; N[i]; ++i)
		t = (t+(N[i]-'0'))%3;
	if(t == 0)
		printf("2\n");
	else
		printf("1\n%d\n", t);
	return 0;
}
