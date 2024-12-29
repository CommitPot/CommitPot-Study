#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n, m, arr[1001][10001] = {0}, w[1001], v[1001];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &v[i], &w[i]);
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (w[i] <= j) arr[i][j] = max(arr[i - 1][j - w[i]] + v[i], arr[i - 1][j]);
            else arr[i][j] = arr[i - 1][j];
        }
    }
    printf("%d", arr[m][n]);
}
