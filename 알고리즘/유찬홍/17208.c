#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n, m, k, arr[101][301][301] = {0}, a[301], b[301];
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%d %d", &a[i], &b[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int l = 1; l <= k; l++) {
                if (j >= a[i] && l >= b[i]) {
                    arr[i][j][l] = max(arr[i - 1][j][l], arr[i - 1][j - a[i]][l - b[i]] + 1);
                } else arr[i][j][l] = arr[i - 1][j][l];
            }
        }
    }
    printf("%d", arr[n][m][k]);
}
