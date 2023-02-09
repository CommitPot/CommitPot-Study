#include <stdio.h>

int main() {
   int N = 0, count = 0;

   scanf("%d", &N);

   for (int i = 1; i <= 500; i++) { // B
       for (int j = i + 1; j <= 500; j++) { // A
           if (j * j - N == i * i) {
               count++;
           }
       }
   }
   printf("%d\n", count);
}
