#include <stdio.h>

int main() {
    int n, count = 2;
    char arr[51];
    scanf("%d %s", &n, arr);
    for (int i = 1; i < n; i++) {
        if (arr[i] == 'S') count++;
        else if (arr[i] == 'L') {
            count++;
            i++;
        }
    }
    printf("%d", count < n ? count : n);
    return 0;
}