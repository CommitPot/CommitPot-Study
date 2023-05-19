#include <stdio.h>

int n, m, vis[10] = {0};

void bt(char *arr, int len) {
    if (len == m) {
        for (int i = 0; i < len - 1; i++) {
            if (arr[i] > arr[i + 1]) return;
        }
        for (int i = 0; i < len; i++) {
            printf("%c ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            arr[len++] = i + 48;
            bt(arr, len);
            len--;
            vis[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    char arr[10];
    bt(arr, 0);
}
