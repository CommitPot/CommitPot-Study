#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int t, n, arr[100000], arr1[100000];
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[j]);
        }
        qsort(arr, n, 4, comp);
        int c = 0, s = 0;
        for (int j = 0; j < n; j++) {
            if (j % 2 == 0) arr1[c++] = arr[j];
        }
        for (int j = n - 1; j >= 0; j--) {
            if (j % 2 == 1) arr1[c++] = arr[j];
        }
        for (int j = 0; j < n - 1; j++) {
            if (abs(arr1[j] - arr1[j + 1]) > s) s = abs(arr1[j] - arr1[j + 1]);
        }
        printf("%d\n", s);
    }
    return 0;
}