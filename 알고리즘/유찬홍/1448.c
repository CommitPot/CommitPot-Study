#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int main() {
    int n, arr[1000000], sum = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, 4, comp);
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] < arr[i] + arr[i + 1]) {
            sum = arr[i - 1] + arr[i] + arr[i + 1];
            break;
        }
    }
    printf("%d", sum);
    return 0;
}