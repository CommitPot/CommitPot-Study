#include <stdio.h>

int main() {
    int n, a, m = 1e9 + 7, dp[2002][2002];
    dp[1][1] = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a);
    n *= 2;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == 1 || j == 1) dp[i][j] = 1;
            else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % m;
        }
    }
    printf("%d %d", dp[n + 1][(n + 1) % 2 == 0 ? (n + 1) / 2 : (n + 1) / 2 + 1], n / 2 * n / 2);
}
