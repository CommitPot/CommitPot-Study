#include <stdio.h>

int main() {
    int t, n, dp[5001][2501] = {};
    scanf("%d", &t);
    for (int i = 0; i < 2501; i++) dp[0][i] = dp[1][i] = 1;
    dp[1][0] = 0;
    for (int i = 2; i < 5001; i++) {
        dp[i][0] = dp[i - 2][1];
        for (int j = 1; j <= (5000 - i) / 2; j++) {
            dp[i][j] = (dp[i - 2][j + 1] + dp[i - 1][j - 1]) % 998244353;
        }
    }
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", dp[n][0] ? dp[n][0] : -1);
    }
}
