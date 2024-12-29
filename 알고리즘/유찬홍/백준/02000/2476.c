#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, max = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int arr[4];
        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
        qsort(arr, 3, 4, comp);
        if (arr[0] == arr[1]) {
            if (arr[1] == arr[2]) {
                int a = 10000 + 1000 * arr[1];
                max = max > a ? max : a;
            } else {
                int a = 1000 + 100 * arr[1];
                max = max > a ? max : a;
            }
        } else {
            if (arr[1] == arr[2]) {
                int a = 1000 + 100 * arr[1];
                max = max > a ? max : a;
            } else {
                int a = 100 * arr[2];
                max = max > a ? max : a;
            }
        }
    }
    printf("%d", max);
}
