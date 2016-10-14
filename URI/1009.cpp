// In the name of Allah, Most Gracious, Most Merciful

// URI/1009
// Salary with Bonus
// implementation
// 
// 
// AC (18/12/2013 - 11:45:35)

#include<cstdio>

int main() {
  char N[128];
  gets(N);
  
  double F, S;
  scanf("%lf %lf", &F, &S);
  printf("TOTAL = R$ %0.2lf\n", F + 0.15 * S);
  return 0;
}
