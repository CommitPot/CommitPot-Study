#include <stdio.h>

int main() {
    int n, dp[1000001] = {};
    scanf("%d", &n);
    dp[0] = 1;
    for (int i = 1; i < 1000000; i <<= 1) {
        for (int j = i; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - i]) % 1000000000;
        }
    }
    printf("%d", dp[n]);
}
