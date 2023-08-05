#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vis[7] = {0}, rs = 1000000;
char arr[7];

void bt(char *arr1, int len, int c) {
    if (c == len) {
        if (rs > atoi(arr1) && atoi(arr) < atoi(arr1)) {
            rs = atoi(arr1);
        }
        return;
    }
    for (int i = 0; i < len; i++) {
        if (vis[i]) continue;
        arr1[c++] = arr[i];
        vis[i] = 1;
        bt(arr1, len, c--);
        vis[i] = 0;
    }
}

int main() {
    char arr1[7];
    scanf("%s", arr);
    int len = strlen(arr);
    for (int i = 0; i < len; i++) {
        vis[i] = 1;
        arr1[0] = arr[i];
        bt(arr1, len, 1);
        vis[i] = 0;
    }
    printf("%d", rs == 1000000 ? 0 : rs);
}
