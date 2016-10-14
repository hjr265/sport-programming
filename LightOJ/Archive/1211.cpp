// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1211
// Intersection of Cubes
// geometry
// 
// 
// AC (2011-09-14 12:06:05)

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Cube {
	int x1, y1, z1, x2, y2, z2;
};

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		Cube a;
		scanf("%d %d %d %d %d %d", &a.x1, &a.y1, &a.z1, &a.x2, &a.y2, &a.z2);
		while(--n) {
			Cube b;
			scanf("%d %d %d %d %d %d", &b.x1, &b.y1, &b.z1, &b.x2, &b.y2, &b.z2);
			Cube m;
			m.x1 = max(min(a.x1, a.x2), min(b.x1, b.x2)), m.y1 = max(min(a.y1, a.y2), min(b.y1, b.y2)), m.z1 = max(min(a.z1, a.z2), min(b.z1, b.z2));
			m.x2 = min(max(a.x1, a.x2), max(b.x1, b.x2)), m.y2 = min(max(a.y1, a.y2), max(b.y1, b.y2)), m.z2 = min(max(a.z1, a.z2), max(b.z1, b.z2));
			if(m.x2 < m.x1 || m.y2 < m.y1 || m.z2 < m.z1)
				m.x1 = 0, m.y1 = 0, m.z1 = 0, m.x2 = 0, m.y2 = 0, m.z2 = 0;
			a = m;
		}
		printf("Case %d: %d\n", no++, abs(a.x2-a.x1)*abs(a.y2-a.y1)*abs(a.z2-a.z1));
	}
	return 0;
}
