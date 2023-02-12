#include <stdio.h>
#include <string.h>

int main() {
    int t, n;
    char arr[81];
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %s", &n, arr);
        int len = strlen(arr);
        for (int j = 0; j < len; j++) {
            if (j + 1 == n) continue;
            printf("%c", arr[j]);
        }
        printf("\n");
    }
    return 0;
}