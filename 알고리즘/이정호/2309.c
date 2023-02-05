#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
   return (*(int *) a - *(int *) b);
}

int main() {

   int sum = 0, k = 0, m = 0;

   int arr[10] = {0,};

   for (int i = 0; i < 9; i++) {
       scanf("%d", &arr[i]);
       sum += arr[i];
   }

   qsort(arr, 9, sizeof(int), comp);

   for (int i = 0; i < 8; i++) {
       for (int j = i+1; j < 9; j++) {
           if (sum - arr[i] - arr[j] == 100) {
               k = i;
               m = j;
               break;
           }
       }
   }

   for(int i=0; i<9; i++) {
       if(i == k || i == m)
           continue;
       printf("%d\n", arr[i]);
   }

}
