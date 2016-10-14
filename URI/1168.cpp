// In the name of Allah, Most Gracious, Most Merciful

// URI/1168
// LED
// implementation, strings
// 
// 
// AC (18/12/2013 - 12:28:24)

#include<cstdio>

int main() {
  int N;
  scanf("%d", &N);
  while(N--) {
    char V[102];
    scanf("%s", V);
    int R = 0;
    for(int i = 0; V[i]; ++i) {
      switch(V[i]) {
        case '1':
          R += 2;
          break;
        case '2':
        case '3':
        case '5':
          R += 5;
          break;
        case '4':
          R += 4;
          break;
        case '0':
        case '6':
        case '9':
          R += 6;
          break;
        case '7':
          R += 3;
          break;
        case '8':
          R += 7;
          break;
      }
    }
    printf("%d leds\n", R);
  }
  return 0;
}
