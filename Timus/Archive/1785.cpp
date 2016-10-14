// In the name of Allah, Most Gracious, Most Merciful

// Timus/1785
// Lost in Localization
// implementation
// 
// 
// AC (22:15:10 28 Apr 2012)

#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	if(n < 5) {
		printf("few\n");
	} else if(n < 10) {
		printf("several\n");
	} else if(n < 20) {
		printf("pack\n");
	} else if(n < 50) {
		printf("lots\n");
	} else if(n < 100) {
		printf("horde\n");
	} else if(n < 250) {
		printf("throng\n");
	} else if(n < 500) {
		printf("swarm\n");
	} else if(n < 1000) {
		printf("zounds\n");
	} else {
		printf("legion\n");
	}
	return 0;
}
