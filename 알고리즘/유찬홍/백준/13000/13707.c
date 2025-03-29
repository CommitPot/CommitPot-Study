#include <stdio.h>

int main() {
    int n, m, dp[5001][2] = {};
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++) dp[i][1] = 1;
    dp[0][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[j][1] = (dp[j - 1][1] + dp[j][0]) % 1000000000;
        }
        for (int j = 1; j <= n; j++) dp[j][0] = dp[j][1];
    }
    printf("%d", dp[n][0]);
}
