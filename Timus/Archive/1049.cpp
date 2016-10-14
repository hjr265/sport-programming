// In the name of Allah, Most Gracious, Most Merciful

// Timus/1049
// Brave Balloonists
// number theory
// 
// 
// AC (15:55:45 29 Apr 2012)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

using namespace std;

typedef long long vlong;

int T[10005];

int main() {
	vlong a[12];
	for(int i = 0; i < 10; ++i)
		scanf("%lld", &a[i]);
	bool f = true;
	vlong r = 1;
	for(vlong i = 2; f; ++i) {
		f = false;
		for(int j = 0; j < 10; ++j) if(i*i <= a[j])
			f= true;
		int k = 1;
		for(int j = 0; j < 10; ++j) if(a[j]%i == 0) {
			while(a[j]%i == 0) {
				a[j] /= i;
				++k;
			}
		}
		r = (r*k)%10;
	}
	CLR(T);
	for(int i = 0; i < 10; ++i)
		++T[a[i]];
	for(int i = 2; i < 10005; ++i) if(T[i] > 0)
		r = (r*(T[i]+1))%10;
	printf("%d\n", r);
	return 0;
}
