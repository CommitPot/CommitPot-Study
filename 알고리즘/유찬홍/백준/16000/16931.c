#include <stdio.h>

int main() {
    int n, m, rs = 0, arr[101][101], a[102][102][102] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= arr[i][j]; k++) {
                a[i][j][k] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= arr[i][j]; k++) {
                if (!a[i][j][k - 1]) rs++;
                if (!a[i][j][k + 1]) rs++;
                if (!a[i][j - 1][k]) rs++;
                if (!a[i][j + 1][k]) rs++;
                if (!a[i - 1][j][k]) rs++;
                if (!a[i + 1][j][k]) rs++;
            }
        }
    }
    printf("%d", rs);
}
