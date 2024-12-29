#include <stdio.h>

int main() {
    int n, dp[16] = {0, 2};
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] * 3;
    printf("%d", dp[n]);
}
