#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char arr[101];
    scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", arr);
        int len = strlen(arr), a = 0;
        for (int j = 0; j < len; j++) {
            if (!a && arr[j] == ' ') {
                printf("god");
                a = 1;
            } else if (a && arr[j] != ' ') printf("%c", arr[j]);
        }
        printf("\n");
    }
    return 0;
}