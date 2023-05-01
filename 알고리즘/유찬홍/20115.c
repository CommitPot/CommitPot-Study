#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, arr[100001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, 4, comp);
    double sum = arr[n - 1];
    for (int i = 0; i < n - 1; i++) {
        sum += (double) arr[i] / 2;
    }
    printf("%.1lf", sum);
}
