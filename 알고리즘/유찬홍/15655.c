#include <stdio.h>
#include <stdlib.h>

int n, m, arr[10], vis[10002] = {0};

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
        if (!vis[arr[i]]) {
            vis[arr[i]] = 1;
            arr1[len] = arr[i];
            bt(arr1, len + 1);
            vis[arr[i]] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int arr1[10] = {0};
    qsort(arr, n, 4, comp);
    bt(arr1, 0);
}
