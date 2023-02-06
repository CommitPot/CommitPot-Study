#include <stdio.h>

int getClap(int N);

int main() {
   int N = 0, count = 0;

   scanf("%d", &N);

   for(int i=1; i<=N; i++) {
       count += getClap(i);
   }

   printf("%d", count);
}

int getClap(int N) {
   int count = 0;
   while (N) {
       if (N % 10 == 3 || N % 10 == 6 || N % 10 == 9) {
           count++;
       }
       N /= 10;
   }
   return count;
}
