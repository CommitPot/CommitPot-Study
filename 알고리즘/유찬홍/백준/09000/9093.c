#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char arr[1001];
    scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
        gets(arr);
        int len = strlen(arr), b = 0;
        for (int j = 0; j <= len; j++) {
            if (arr[j] == ' ' || j == len) {
                for (int k = j - 1; k >= b; k--) {
                    printf("%c", arr[k]);
                }
                printf(" ");
                b = j + 1;
            }
        }
        printf("\n");
    }
    return 0;
}