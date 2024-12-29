#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int main() {
    int n, m, dp[1003][1003][3] = {};
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1, k; j <= m; j++) {
            scanf("%d", &k);
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = k;
        }
    }
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            if (!i || i == n + 1 || !j || j == m + 1) dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = 1e9;
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j][0] += min(dp[i - 1][j][1], dp[i - 1][j + 1][2]);
            dp[i][j][1] += min(dp[i - 1][j - 1][0], dp[i - 1][j + 1][2]);
            dp[i][j][2] += min(dp[i - 1][j - 1][0], dp[i - 1][j][1]);
        }
    }
    int rs = 1e9;
    for (int i = 1; i <= m; i++) {
        rs = min(min(dp[n][i][0], dp[n][i][1]), min(dp[n][i][2], rs));
    }
    printf("%d", rs);
}
