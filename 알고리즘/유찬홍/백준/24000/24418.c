#include <stdio.h>

int main() {
    int n, i, j, a[16][16];
    scanf("%d", &n);
    for (i = 0; i < n * n; i++) scanf("%d", &j);
    for (i = 0; i <= n; i++) a[i][0] = a[0][i] = 1;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            a[i][j] = a[i - 1][j] + a[i][j - 1];
        }
    }
    printf("%d %d", a[n][n], n * n);
}
