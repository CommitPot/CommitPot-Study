#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, q, arr[300001] = {0}, a, b;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n + 1, 4, comp);
    for (int i = 2; i <= n; i++) {
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", arr[b] - arr[a - 1]);
    }
    return 0;
}