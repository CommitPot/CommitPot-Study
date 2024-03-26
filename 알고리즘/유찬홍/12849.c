#include <stdio.h>

int main() {
    int n, dp[8][2] = {0};
    char *m[8] = {"17", "026", "1356", "245", "35", "2346", "1257", "06"};
    dp[4][0] = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; m[j][k] != 0; k++) {
                dp[j][1] = (dp[j][1] + dp[m[j][k] - 48][0]) % 1000000007;
            }
        }
        for (int j = 0; j < 8; j++) {
            dp[j][0] = dp[j][1];
            dp[j][1] = 0;
        }
    }
    printf("%d", dp[4][0]);
}
