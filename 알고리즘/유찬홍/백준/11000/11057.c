#include <stdio.h>

int main() {
    int n, dp[2][10] = {}, dp1[1001] = {10,};
    for (int i = 0; i < 10; i++) dp[0][i] = 1;
    for (int i = 1; i < 1001; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                dp[1][j] = (dp[1][j] + dp[0][k]) % 10007;
            }
            dp1[i] = (dp1[i] + dp[1][j]) % 10007;
        }
        for (int j = 0; j < 10; j++) dp[0][j] = dp[1][j], dp[1][j] = 0;
    }
    scanf("%d", &n);
    printf("%d", dp1[n - 1]);
}
