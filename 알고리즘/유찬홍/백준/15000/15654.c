#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m, vis[10] = {0};
int arr[10], arr1[10];

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

void bt(int len) {
    if (len == m) {
        for (int i = 0; i < len; i++) {
            printf("%d ", arr1[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            arr1[len] = arr[i];
            bt(len + 1);
            vis[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, 4, comp);
    bt(0);
}
