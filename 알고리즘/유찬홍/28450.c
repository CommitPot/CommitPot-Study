#include <stdio.h>

int main() {
    int n, m, h;
    long long int dp[1001][1001] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%lld", &dp[i][j]);
        }
    }
    scanf("%d", &h);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j == 1 || i == 1) {
                if (j == 1) dp[i][j] += dp[i - 1][j];
                else dp[i][j] += dp[i][j - 1];
            } else {
                dp[i][j] += dp[i][j - 1] > dp[i - 1][j] ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }
    if (dp[n][m] > h) {
        printf("NO");
        return 0;
    }
    printf("YES\n%lld", dp[n][m]);
}
