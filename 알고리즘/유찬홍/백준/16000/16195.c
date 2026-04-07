#include <stdio.h>

int main() {
    int t, n, m, dp[1001][1001] = {}, M = 1000000009;
    scanf("%d", &t);
    dp[1][1] = dp[2][1] = dp[2][2] = dp[3][1] = dp[3][3] = 1;
    dp[3][2] = 2;
    for (int i = 4; i < 1001; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 2][j - 1]) % M + dp[i - 3][j - 1]) % M;
        }
    }
    while (t--) {
        scanf("%d %d", &n, &m);
        int r = 0;
        for (int i = 1; i <= m; i++) r = (r + dp[n][i]) % M;
        printf("%d\n", r);
    }
}
