#include <stdio.h>

int main() {
    int t, n, dp[2][7];
    char s[8];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < 7; i++) dp[0][i] = dp[1][i] = 0;
        dp[0][1] = 1;
        for (int i = 1; i <= n; i++) {
            scanf(" %[^\n]", s);
            for (int j = 0; j < 7; j++) {
                if (dp[0][j]) {
                    dp[1][(s[0] == '+' ? j + s[2] - 48 : j * (s[2] - 48)) % 7] = 1;
                    dp[1][(s[4] == '+' ? j + s[6] - 48 : j * (s[6] - 48)) % 7] = 1;
                }
            }
            for (int j = 0; j < 7; j++) {
                dp[0][j] = dp[1][j];
                dp[1][j] = 0;
            }
        }
        printf("%s\n", dp[0][0] ? "LUCKY" : "UNLUCKY");
    }
}
