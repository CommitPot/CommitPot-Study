#include <stdio.h>
#include <stdlib.h>

int n, m, arr[10];

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

void bt(int *arr1, int len) {
    if (len && arr1[len - 1] < arr1[len - 2]) return;
    if (len == m) {
        for (int i = 0; i < len; i++) {
            printf("%d ", arr1[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        arr1[len] = arr[i];
        bt(arr1, len + 1);
    }
}

int main() {
    int arr1[10] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, 4, comp);
    bt(arr1, 0);
}
