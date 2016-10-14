// In the name of Allah, Most Gracious, Most Merciful

// Live Archive/4055
// Bachelor Arithmetic
// implementation
// 
// 
// AC (2011-10-05 19:35:59)

#include <cstdio>

typedef long long vlong;

int main() {
	int no = 1;
	vlong B, S;
	while(scanf("%lld %lld", &B, &S) == 2 && (B != 0 || S != 0)) {
		printf("Case %d: ", no++);
		if(B == 1)
			printf(":-\\\n");
		else if(S >= B)
			printf(":-|\n");
		else if(S*(B-1) > (S-1)*B)
			printf(":-(\n");
		else if(S*(B-1) < (S-1)*B)
			printf(":-)\n");
		else
			printf(":-|\n");
	}
	return 0;
}
