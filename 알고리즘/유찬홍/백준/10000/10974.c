#include <stdio.h>

int n, vis[10] = {0};

void bt(int *arr, int cnt) {
    if (cnt == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]){
            vis[i] = 1;
            arr[cnt++] = i;
            bt(arr, cnt);
            cnt--;
            vis[i] = 0;
        }
    }
}

int main() {
    int arr[10] = {0};
    scanf("%d", &n);
    bt(arr, 0);
}
