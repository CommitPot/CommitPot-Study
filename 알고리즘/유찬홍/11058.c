#include <stdio.h>

int main() {
    int n;
    long long dp[101];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        dp[i] = i;
        for (int j = 1; j < i - 2; j++) {
            long long a = dp[i - 2 - j] * (j + 1);
            dp[i] = a > dp[i] ? a : dp[i];
        }
    }
    printf("%lld", dp[n]);
}
