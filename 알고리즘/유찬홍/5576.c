#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int main() {
    int arr[10], arr1[10], sum, sum1;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr1[i]);
    }
    qsort(arr, 10, 4, comp);
    qsort(arr1, 10, 4, comp);
    sum = arr[0] + arr[1] + arr[2];
    sum1 = arr1[0] + arr1[1] + arr1[2];
    printf("%d %d", sum, sum1);
    return 0;
}