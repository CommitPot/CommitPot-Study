#include <stdio.h>
#include <stdlib.h>

typedef struct spot {
   int x;
   int y;
} Spot;

int comp(const void *x, const void *y) {
   Spot *p1 = (Spot *) x;
   Spot *p2 = (Spot *) y;

   if (p1->x < p2->x) {
       return -1;
   } else if (p1->x > p2->x) {
       return 1;
   } else if (p1->x == p2->x) {
       if (p1->y < p2->y) return -1;
       else if (p1->y > p2->y) return 1;
   }
   return 0;
}

int main() {

   int n = 0;
   scanf("%d", &n);

   Spot *arr = (Spot *) malloc(sizeof(Spot) * n);

   for (int i = 0; i < n; i++) {
       scanf("%d %d", &arr[i].x, &arr[i].y);
   }

   qsort(arr, n, 8, comp);

   for (int i = 0; i < n; i++) {
       printf("%d %d\n", arr[i].x, arr[i].y);
   }

   free(arr);
}
