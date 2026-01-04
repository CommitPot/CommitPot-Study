#include <stdio.h>
#include <string.h>

int dp[201][100];

int f(int n, int k) {
    if (~n & 1 || !k) return 0;
    if (n == 1) return 1;
    if (dp[n][k] > -1) return dp[n][k];
    dp[n][k] = 0;
    for (int i = 1; i < n; i += 2) {
        dp[n][k] = (dp[n][k] + f(i, k - 1) * f(n - i - 1, k - 1)) % 9901;
    }
    return dp[n][k];
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    memset(dp, -1, sizeof(dp));
    printf("%d", (f(n, k) - f(n, k - 1) + 9901) % 9901);
}
