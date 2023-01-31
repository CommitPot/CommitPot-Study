#include <stdio.h>

int main() {
   long long int N = 0;

   scanf("%lld", &N);

   if (N % 7 == 0 || N % 7 == 2) {
       printf("CY");
   } else { printf("SK"); }
}

