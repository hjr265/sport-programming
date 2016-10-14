// In the name of Allah, Most Gracious, Most Merciful

// URI/1010
// Simple Calculate
// implementation
// 
// 
// AC (18/12/2013 - 12:03:54)

#include<cstdio>

int main() {
  int C[2], Q[2];
  double P[2], R = 0;
  for(int i = 0; i < 2; ++i) {
  	scanf("%d %d %lf", &C[i], &Q[i], &P[i]);
  	R += Q[i] * P[i];
  }
  printf("VALOR A PAGAR: R$ %0.2lf\n", R);
  return 0;
}
