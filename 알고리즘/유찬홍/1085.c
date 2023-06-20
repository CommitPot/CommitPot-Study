#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int x, y, w, h, arr[5];
    scanf("%d %d %d %d", &x, &y, &w, &h);
    arr[0] = x;
    arr[1] = y;
    arr[2] = h - y;
    arr[3] = w - x;
    qsort(arr, 4, 4, comp);
    printf("%d", arr[0]);
}
