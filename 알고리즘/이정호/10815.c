#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 500000

int comp(const void *a, const void *b) {
   return *(int *) a - *(int *) b;
}

int main() {
   int N = 0, M = 0, a = 0;

   int arrN[MAX_SIZE + 1] = {0,};
   int arrM[MAX_SIZE + 1] = {0,};

   scanf("%d", &N);

   for (int i = 0; i < N; i++) scanf("%d", &arrN[i]);

   qsort(arrN, N, 4, comp);

   scanf("%d", &M);

   for (int j = 0; j < M; j++) {
       int s = 0, e = N;
       scanf("%d", &a);
       while (s < e) {
           int mid = (s + e) / 2;
           if (arrN[mid] > a) { e = mid; }
           else if (arrN[mid] < a) { s = mid + 1; }
           else {
               arrM[j] = 1;
               break;
           }
       }
   }

   for(int i=0; i<M; i++) {
       printf("%d ", arrM[i]);
   }
}
