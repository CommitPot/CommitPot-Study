#include <stdio.h>

int main() {
    int n, q, r = 0, a[2][100][102] = {};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[0][i][j]);
        }
    }
    scanf("%d", &q);
    for (int i = 0, j; i < q; i++) {
        scanf("%d", &j);
        if (j & 1) {
            scanf("%d", &j);
            a[r][j - 1][n]++;
        } else {
            r = !r;
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    a[r][l][n - k - 1] = a[!r][k][(l + n - a[!r][k][n]) % n];
                }
            }
            for (int k = 0; k < n; k++) a[!r][k][n] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[r][i][(j + n - a[r][i][n]) % n]);
        }
        printf("\n");
    }
}
