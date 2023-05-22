#include <stdio.h>

int n, m;

void bt(char *arr, int len) {
    if (len == m) {
        for (int i = 0; i < len; i++) {
            printf("%c ", arr[i]);
        }
        printf("\n");
        return;
    }
    for (char i = 49; i <= n + 48; i++) {
        arr[len++] = i;
        bt(arr, len);
        len--;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    char arr[10];
    bt(arr, 0);
}
