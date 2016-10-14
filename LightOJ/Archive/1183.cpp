// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1183
// Computing Fast Average
// trees
// 
// 
// AC (2012-05-26 09:22:03)

#include <cstdio>
#include <cstring>

#define SET(c) memset(c, -1, sizeof(c))
#define CLR(c) memset(c, 0, sizeof(c))

typedef long long vlong;

class Segtree {
	vlong t[100002*5*2], s[100002*5*2];
	
public:
	Segtree() {
		clear();
	}
	
	void clear() {
		SET(s);
		CLR(t);
	}
	
	void set(int i, int j, vlong v, int u = 1, int l = 1, int r = 100002) {
		if(s[u] != -1) {
			t[u] = s[u];
			s[2*u] = (s[u]/(r-l+1))*((l+r)/2-l+1);
			s[2*u+1] = (s[u]/(r-l+1))*(r-(l+r)/2);
			s[u] = -1;
		}
		if(r < i || l > j)
			return;
		if(l >= i && r <= j) {
			s[u] = -1;
			t[u] = v*(r-l+1);
			s[2*u] = v*((l+r)/2-l+1);
			s[2*u+1] = v*(r-(l+r)/2);
		} else {
			int m = (l+r)/2;
			set(i, j, v, 2*u, l, m);
			set(i, j, v, 2*u+1, m+1, r);
			t[u] = t[2*u]+t[2*u+1];
		}
	}
	
	vlong sum(int i, int j, int u = 1, int l = 1, int r = 100002) {
		if(s[u] != -1) {
			t[u] = s[u];
			s[2*u] = (s[u]/(r-l+1))*((l+r)/2-l+1);
			s[2*u+1] = (s[u]/(r-l+1))*(r-(l+r)/2);
			s[u] = -1;
		}
		if(r < i || l > j)
			return 0;
		if(l >= i && r <= j) {
			return t[u];
		} else {
			int m = (l+r)/2;
			return sum(i, j, 2*u, l, m)+sum(i, j, 2*u+1, m+1, r);
		}
	}
};

vlong gcd(vlong a, vlong b) {
	return b == 0 ? a : gcd(b, a%b);
}

Segtree r;

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n, q;
		scanf("%d %d", &n, &q);
		r.clear();
		printf("Case %d:\n", no++);
		while(q--) {
			int c, i, j, v;
			scanf("%d %d %d", &c, &i, &j);
			switch(c) {
			case 1:
				scanf("%d", &v);
				r.set(i+1, j+1, v);
				break;
			case 2:
				vlong zn = r.sum(i+1, j+1), zd = j-i+1, zg = gcd(zn, zd);
				zn /= zg;
				zd /= zg;
				if(zd == 1)
					printf("%lld\n", zn);
				else
					printf("%lld/%lld\n", zn, zd);
				break;
			}
		}
	}
	return 0;
}
