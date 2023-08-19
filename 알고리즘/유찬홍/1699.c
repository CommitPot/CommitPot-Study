#include <stdio.h>

int main() {
    int n, dp[100001] = {0};
    scanf("%d", &n);
    for (int i = 1; i * i <= n; i++) dp[i * i] = 1;
    for (int i = 1; i <= n; i++) if (!dp[i]) dp[i] = 1000000000;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j < i; j++) {
            if (dp[j * j] + dp[i - j * j] < dp[i]) dp[i] = dp[j * j] + dp[i - j * j];
        }
    }
    printf("%d", dp[n]);
}
