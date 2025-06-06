#include <stdio.h>

int main() {
    int n, m, k, dp[101][101];
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < 101; i++) dp[i][0] = dp[0][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            if (dp[i][j] > 1e9) dp[i][j] = 1e9;
        }
    }
    if (dp[n][m] < k) {
        printf("-1");
        return 0;
    }
    while (n || m) {
        if (dp[n - 1][m] >= k && n) {
            printf("a");
            n--;
        } else {
            printf("z");
            k -= dp[n - 1][m];
            m--;
        }
    }
}
