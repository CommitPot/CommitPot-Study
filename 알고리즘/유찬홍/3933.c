#include <stdio.h>

int main() {
    int n, dp[5][32769] = {};
    dp[0][0] = 1;
    for (int i = 1; i <= 181; i++) {
        for (int j = 0; j + i * i < 32769; j++) {
            for (int k = 1; k < 5; k++) {
                dp[k][j + i * i] += dp[k - 1][j];
            }
        }
    }
    while (scanf("%d", &n) != 0) {
       if (!n) break;
        printf("%d\n", dp[1][n] + dp[2][n] + dp[3][n] + dp[4][n]);
    }
}
