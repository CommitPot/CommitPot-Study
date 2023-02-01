#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int lowerbound(int *arr, int f, int s, int e) {
    while (s < e) {
        int mid = (s + e) / 2;
        if (arr[mid] < f) s = mid + 1;
        else e = mid;
    }
    return e;
}

int main() {
    int n, c = 0, arr[1000000], arr1[1000000], arr2[1000000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        arr1[i] = arr[i];
    }
    qsort(arr1, n, 4, comp);
    arr2[0] = 0;
    for (int i = 1; i < n; i++) {
        if (arr1[i] == arr1[i - 1]) arr2[i] = c;
        else arr2[i] = ++c;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = arr2[lowerbound(arr1, arr[i], 0, n)];
        printf("%d ", arr[i]);
    }
    return 0;
}