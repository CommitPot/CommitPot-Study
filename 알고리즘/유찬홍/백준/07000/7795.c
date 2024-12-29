#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int upperbound(const int *arr, int f, int s, int e) {
    while (s < e) {
        int mid = (s + e) / 2;
        if (arr[mid] < f) s = mid + 1;
        else e = mid;
    }
    return e;
}

int main() {
    int t, n, m, arr[20000], arr1[20000];
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &n, &m);
        int count = 0;
        arr1[0] = 0;
        for (int j = 0; j < n; j++) scanf("%d", &arr[j]);
        for (int j = 1; j <= m; j++) scanf("%d", &arr1[j]);
        qsort(arr1, m + 1, 4, comp);
        for (int j = 0; j < n; j++) {
            count += upperbound(arr1, arr[j], 0, m + 1) - 1;
        }
        printf("%d\n", count);
    }
    return 0;
}