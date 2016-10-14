// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1214
// Large Division
// big integer
// 
// 
// AC (2011-09-16 17:17:37)

#include <cstdio>
#include <cstring>

#define CLR(c) memset(c, 0, sizeof(c))

typedef long long vlong;

template<int c> struct Bint {
	vlong v[c];
	
	Bint(char s[]) {
		CLR(v);
		for(int i = 0; s[i]; ++i) {
			if(s[i] == '-')
				continue;
			char e = s[i] - '0';
			for(int j = 0; j < c; ++j) {
				v[j] = v[j]*10+e;
				e = v[j]>>32;
				v[j] &= (1LL<<32)-1;
			}
		}
	}
	
	int mod(int x) {
		vlong r = 0;
		for(int i = c-1; i >= 0; --i)
			r = ((r<<32)|v[i])%x;
		return r;
	}
};

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		char t[210];
		int b;
		scanf("%s %d", &t, &b);
		Bint<128> a(t);
		printf("Case %d: %s\n", no++, a.mod(b) == 0 ? "divisible" : "not divisible");
	}
	return 0;
}
