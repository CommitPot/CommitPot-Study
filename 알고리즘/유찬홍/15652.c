#include <stdio.h>

int n, m;

void bt(char *arr, int len) {
    if (len > 0 && arr[len - 1] < arr[len - 2]) return;
    if (len == m) {
        for (int i = 0; i < len; i++) {
            printf("%c ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        arr[len++] = i + 48;
        bt(arr, len);
        len--;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    char arr[10];
    bt(arr, 0);
}
