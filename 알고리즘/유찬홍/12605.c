#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char arr[100], stack[100];
    scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]s ", arr);
        int top = -1, c = 0, len = strlen(arr);
        for (int j = 0; j <= len; j++) {
            if (arr[j] == ' ' || j == len) {
                for (int k = j - 1; k >= c; k--) {
                    stack[++top] = arr[k];
                }
                stack[++top] = ' ';
                c = j + 1;
            }
        }
        printf("Case #%d:", i + 1);
        while (top >= 0) {
            printf("%c", stack[top--]);
        }
        printf("\n");
    }
    return 0;
}