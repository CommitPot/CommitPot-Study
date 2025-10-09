#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int main() {
    int c, n, w[21], v[21], dp[21][1001] = {};
    scanf("%d %d", &c, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }
    for (int i = 0; i < n; i++) {
        dp[i][1] = w[i];
        for (int j = 2; j <= c; j++) {
            if (j >= v[i]) dp[i][j] = dp[i][j - v[i]] + w[i];
            else dp[i][j] = dp[i][j - 1];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= c; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j]);
            if (j >= v[i]) dp[i][j] = min(dp[i][j], min(dp[i - 1][j - v[i]], dp[i][j - v[i]]) + w[i]);
        }
    }
    printf("%d", dp[n - 1][c]);
}
