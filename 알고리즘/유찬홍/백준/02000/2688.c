#include <stdio.h>

int main() {
    int t, n;
    long long dp[2][10] = {}, dp1[65] = {10,};
    for (int i = 0; i < 10; i++) dp[0][i] = 1;
    for (int i = 1; i < 65; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                dp[1][j] += dp[0][k];
            }
            dp1[i] += dp[1][j];
        }
        for (int j = 0; j < 10; j++) dp[0][j] = dp[1][j], dp[1][j] = 0;
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%lld\n", dp1[n - 1]);
    }
}
