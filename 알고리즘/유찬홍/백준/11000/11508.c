#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, arr[100000], sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), comp);
    n--;
    while (n > 1) {
        sum += arr[n] + arr[n - 1];
        n -= 3;
    }
    while (n >= 0) {
        sum += arr[n];
        n--;
    }
    printf("%d", sum);
    return 0;
}