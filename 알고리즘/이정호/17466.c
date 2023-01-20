#include <stdio.h>

int main() {
   long long int N = 0, K = 0, fact1 = 1;

   scanf("%lld %lld", &N, &K);

   for (int i = 1; i <= N; i++) {
       fact1 = ((fact1 * (i % K))) % K; // N!
   }

   printf("%lld", fact1 % K);
}

