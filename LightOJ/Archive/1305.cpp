// In the name of Allah, Most Gracious, Most Merciful

// LightOJ/1305
// Area of a Parallelogram
// geometry
// 
// 
// AC (2011-09-14 12:13:49)

#include <cstdio>
#include <cstdlib>

int main() {
	int T, no = 1;
	scanf("%d", &T);
	while(T--) {
		int Ax, Ay, Bx, By, Cx, Cy;
		scanf("%d %d %d %d %d %d", &Ax, &Ay, &Bx, &By, &Cx, &Cy);
		int Dx = Ax+Cx-Bx, Dy = Ay+Cy-By;
		printf("Case %d: %d %d %d\n", no++, Dx, Dy, abs((Ax*By+Bx*Cy+Cx*Dy+Dx*Ay-Ay*Bx-By*Cx-Cy*Dx-Dy*Ax)/2));
	}
	return 0;
}
