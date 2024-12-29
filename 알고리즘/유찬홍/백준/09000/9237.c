#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int main() {
    int n, arr[100000], big = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, 4, comp);
    for (int i = 0; i < n; i++) {
        arr[i] += i + 1;
        if (arr[i] > big) big = arr[i];
    }
    printf("%d", big + 1);
    return 0;
}