#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int bs(const int *arr, int n, int num) {
    int s = 0, e = n - 1, mid, a = 0, c = 0;
    while (s <= e) {
        mid = (s + e) / 2;
        if (arr[mid] < num) s = mid + 1;
        else {
            a = mid;
            e = mid - 1;
        }
        if (arr[mid] == num) c++;
    }
    if (c) return a;
    return -1;
}

int main() {
    int n, m, o, arr[200001];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, 4, comp);
    for (int i = 0; i < m; i++) {
        scanf("%d", &o);
        printf("%d\n", bs(arr, n, o));
    }
    return 0;
}