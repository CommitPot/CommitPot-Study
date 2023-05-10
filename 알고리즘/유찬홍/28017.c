#include <stdio.h>

int main() {
    int n, m, arr[501][501], dp[501][501] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &arr[i][j]);
            dp[i][j] = arr[i][j];
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int min = 50000000;
            for (int k = 1; k <= m; k++) {
                if (j != k && min > dp[i - 1][k]) min = dp[i - 1][k];
            }
            dp[i][j] += min;
        }
    }
    int min = 500000000;
    for (int i = 1; i <= m; i++) {
        if (dp[n][i] < min) min = dp[n][i];
    }
    printf("%d", min);
}
