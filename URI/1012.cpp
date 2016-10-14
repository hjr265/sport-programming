// In the name of Allah, Most Gracious, Most Merciful

// URI/1012
// Area
// implementation
// 
// 
// AC (18/12/2013 - 12:04:02)

#include<cstdio>

int main() {
  double A, B, C;
  scanf("%lf %lf %lf", &A, &B, &C);
  printf("TRIANGULO: %0.3lf\n", 0.5 * A * C);
  printf("CIRCULO: %0.3lf\n", 3.14159 * C * C);
  printf("TRAPEZIO: %0.3lf\n", 0.5 * (A + B) * C);
  printf("QUADRADO: %0.3lf\n", B * B);
  printf("RETANGULO: %0.3lf\n", A * B);
  return 0;
}
