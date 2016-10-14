// In the name of Allah, Most Gracious, Most Merciful

// URI/1014
// Consumption
// implementation
// 
// 
// AC (18/12/2013 - 12:04:17)

#include<cmath>
#include<cstdio>

using namespace std;

int main() {
  double x1, y1, x2, y2;
  scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
  printf("%0.4lf\n", sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
  return 0;
}
