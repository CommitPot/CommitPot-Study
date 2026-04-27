#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char a[201][403];
    memset(a, 32, sizeof(a));
    scanf("%d", &n);
    for (int i = 0; i < n * 2; i++) a[i][n * 2 - i - 1] = '*';
    for (int i = 1; i <= n; i++) {
        a[i - 1][n * 3 + 1 - i] = a[i - 1][n * 3 + 1 + i] = '*';
    }
    for (int i = n; i > 0; i--) {
        a[n * 2 - i][n * 3 + 1 - i] = a[n * 2 - i][n * 3 + 1 + i] = '*';
    }
    for (int i = 0; i < n * 2; i++) {
        a[i][4 * n + 2] = 0;
        printf("%s\n", a[i]);
    }
}
