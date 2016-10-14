// In the name of Allah, Most Gracious, Most Merciful

// URI/1013
// The Greatest
// implementation
// 
// 
// AC (18/12/2013 - 12:04:08)

#include<cmath>
#include<cstdio>

using namespace std;

int main() {
  int R;
  scanf("%d", &R);
  for(int i = 0; i < 2; ++i) {
  	int t;
  	scanf("%d", &t);
  	R = (R + t + abs(R - t)) / 2;
  }
  printf("%d eh o maior\n", R);
  return 0;
}
