#include <stdio.h>
#include <math.h>

#define MAX_SIZE 1000000

int main() {
   int M = 0, N = 0;

   int arr[MAX_SIZE + 1] = {0,};

   scanf("%d %d", &M, &N);

   int len = sqrt(MAX_SIZE);

   for (int i = 2; i <= len; i++) {
       if (arr[i] == 0) {
           for (int j = i * 2; j <= MAX_SIZE; j += i) {
               arr[j] = 1;
           }
       }
   }

   for (int i = M; i <= N; i++) {
       if (arr[i] == 0 && i != 1) { printf("%d\n", i); }
   }

}
