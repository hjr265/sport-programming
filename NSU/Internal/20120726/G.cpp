// In the name of Allah, Most Gracious, Most Merciful

// /
// 
// 
// 
// 
// ??

#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define SET(c, v) memset(c, v, sizeof(c))
#define LEN(c) (sizeof(c)/sizeof(c[0]))
#define ALL(c) c.begin(), c.end()
#define SLC(c, n) c, c+(n)

using namespace std;

typedef unsigned int uint;
typedef long long vlong;
typedef unsigned long long uvlong;

const double EPS = 1e-12;
const double PI = acos(-1.0);

enum {
	
};

double mid(double Ax, double Bx) {
	return (Ax+Bx)/2;
}

double dist(double Ax, double Ay, double Bx, double By) {
	return sqrt((Ax-Bx)*(Ax-Bx)+(Ay-By)*(Ay-By));
}

int main() {
	int P;
	scanf("%d", &P);
	while(P--) {
		int N;
		scanf("%d", &N);
		double Bx, Cx, Cy, Dx, Dy;
		scanf("%lf %lf %lf %lf %lf", &Bx, &Cx, &Cy, &Dx, &Dy);
		double Apx = mid(Bx, Cx), Apy = mid(0, Cy),
			Bpx = mid(Cx, Dx), Bpy = mid(Cy, Dy),
			Cpx = mid(0, Dx), Cpy = mid(0, Dy),
			Dpx = mid(0, Bx), Dpy = mid(0, 0);
		double ApB = dist(Apx, Apy, Bx, 0),
			BpC = dist(Bpx, Bpy, Cx, Cy),
			CpD = dist(Cpx, Cpy, Dx, Dy),
			ADp = dist(0, 0, Dpx, Dpy);
		double AAp = dist(0, 0, Apx, Apy),
			BBp = dist(Bx, 0, Bpx, Bpy),
			CCp = dist(Cx, Cy, Cpx, Cpy),
			DDp = dist(Dx, Dy, Dpx, Dpy);
		double AB = dist(0, 0, Bx, 0),
			BC = dist(Bx, 0, Cx, Cy),
			CD = dist(Cx, Cy, Dx, Dy),
			AD = dist(0, 0, Dx, Dy),
			AC = dist(0, 0, Cx, Cy),
			BD = dist(Bx, 0, Dx, Dy);
		double At = acos((AB*AB+AD*AD-BD*BD)/(2*AB*AD)),
			Bt = acos((AB*AB+BC*BC-AC*AC)/(2*AB*BC)),
			Ct = acos((CD*CD+BC*BC-BD*BD)/(2*CD*BC)),
			Dt = acos((CD*CD+AD*AD-AC*AC)/(2*CD*AD));
		double Atx = acos((AB*AB+AAp*AAp-ApB*ApB)/(2*AB*AAp)),
			Btx = acos((BC*BC+BBp*BBp-BpC*BpC)/(2*BC*BBp)),
			Ctx = acos((CD*CD+CCp*CCp-CpD*CpD)/(2*CD*CCp)),
			Dtx = acos((AD*AD+DDp*DDp-ADp*ADp)/(2*AD*DDp));
		double ABBp = Bt-Btx,
			AAeB = PI-ABBp-Atx,
			AAe = AB/sin(AAeB)*sin(ABBp),
			ZAl = 0.5*AB*AAe*sin(Atx);
		double BCCp = Ct-Ctx,
			BBeC = PI-BCCp-Btx,
			BBe = BC/sin(BBeC)*sin(BCCp),
			ZBob = 0.5*BC*BBe*sin(Btx);
		double CDDp = Dt-Dtx,
			CCeD = PI-CDDp-Ctx,
			CCe = CD/sin(CCeD)*sin(CDDp),
			ZChas = 0.5*CD*CCe*sin(Ctx);
		double DAAp = At-Atx,
			DDeA = PI-DAAp-Dtx,
			DDe = AD/sin(DDeA)*sin(DAAp),
			ZDave = 0.5*AD*DDe*sin(Dtx);
		double ZEmily = 0.5*(Bx*Cy+Cx*Dy-Cy*Dx)-ZAl-ZBob-ZChas-ZDave;
		double DeAe = AAe-(AD/sin(DDeA)*sin(Dtx)),
			AeBe = BBe-(AB/sin(AAeB)*sin(Atx)),
			BeCe = CCe-(BC/sin(BBeC)*sin(Btx)),
			CeDe = DDe-(CD/sin(CCeD)*sin(Ctx)),
			TEmily = ceil((DeAe+AeBe+BeCe+CeDe)*16.5);
		printf("%d %0.3lf %0.3lf %0.3lf %0.3lf %0.3lf %0.0lf\n", N, ZAl/160, ZBob/160, ZChas/160, ZDave/160, ZEmily/160, TEmily);
		
		
	}
	return 0;
}
