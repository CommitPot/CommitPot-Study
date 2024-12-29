#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, l, arr[10000], count = 0;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, 4, comp);
    for (int i = 0; i < n; i++) {
        if (arr[i] > i + l) {
            break;
        }
        else count = i + 1 + l;
    }
    printf("%d", count);
    return 0;
}