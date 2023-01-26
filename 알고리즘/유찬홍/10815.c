#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, m, a, arr[500000], arr1[500000] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, 4, comp);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int s = 0, e = n;
        scanf("%d", &a);
        while (s < e) {
            int mid = (s + e) / 2;
            if (arr[mid] > a) e = mid;
            else if (arr[mid] < a) s = mid + 1;
            else {
                arr1[i] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        printf("%d ", arr1[i]);
    }
}