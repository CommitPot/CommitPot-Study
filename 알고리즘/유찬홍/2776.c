#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    if (*(int *) a > *(int *) b) return 1;
    else if (*(int *) a < *(int *) b) return -1;
    else return 0;
}

int bs(const int *arr, int n, int num) {
    int s = 0, e = n - 1;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (arr[mid] == num) return 1;
        else if (arr[mid] < num) s = mid + 1;
        else e = mid - 1;
    }
    return 0;
}

int main() {
    int t, n, m, arr[1000001], arr1[1000001];
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++) scanf("%d", &arr[j]);
        qsort(arr, n, sizeof(int), comp);
        scanf("%d", &m);
        for (int j = 0; j < m; j++) scanf("%d", &arr1[j]);
        for (int j = 0; j < m; j++) printf("%d\n", bs(arr, n, arr1[j]));
    }
    return 0;
}