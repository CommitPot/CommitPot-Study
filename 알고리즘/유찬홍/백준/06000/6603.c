#include <stdio.h>

int n, arr[14], vis[14] = {0};

void bt(int *arr1, int len) {
    if (len > 1 && arr1[len - 1] < arr1[len - 2]) {
        return;
    }
    if (len == 6) {
        for (int i = 0; i < 6; i++) {
            printf("%d ", arr1[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            arr1[len++] = arr[i];
            bt(arr1, len);
            len--;
            vis[i] = 0;
        }
    }
}

int main() {
    while (1) {
        int arr1[14];
        scanf("%d", &n);
        if (!n) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        bt(arr1, 0);
        for (int i = 0; i < 14; i++) {
            vis[i] = 0;
        }
        printf("\n");
    }
}
