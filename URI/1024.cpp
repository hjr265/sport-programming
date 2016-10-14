// In the name of Allah, Most Gracious, Most Merciful

// URI/1024
// Encryption
// implementation, strings
// 
// 
// AC (18/12/2013 - 12:41:18)

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char M[1002];

int main() {
  int N;
  scanf("%d\n", &N);
  while(N--) {
    gets(M);
    for(int i = 0; M[i]; ++i) if(M[i] >= 'a' && M[i] <= 'z' || M[i] >= 'A' && M[i] <= 'Z') {
      M[i] += 3;
    }
    int Ml = strlen(M);
    for(int i = 0; i < Ml / 2; ++i) {
      swap(M[i], M[Ml-i-1]);
    }
    for(int i = Ml / 2; M[i]; ++i) {
      M[i] -= 1;
    }
    printf("%s\n", M);
  }
  return 0;
}
