#include <stdio.h>

int main() {
    int n, dp[41] = {0, 1};
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    printf("%d %d", dp[n], n - 2);
    return 0;
}