#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int comp1(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int main() {
    int n, arr[100], arr1[100], sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    qsort(arr, n, 4, comp);
    qsort(arr1, n, 4, comp1);
    for (int i = 0; i < n; i++) {
        sum += arr[i] * arr1[i];
    }
    printf("%d", sum);
}