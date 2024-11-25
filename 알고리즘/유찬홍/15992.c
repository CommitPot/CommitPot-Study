#include <stdio.h>

int main() {
    int n, e = 1e9 + 9, dp[1005][1005] = {};
    dp[3][0] = 1;
    for (int i = 3; i < 1004; i++) {
        for (int j = 1; j < 1001; j++) {
            dp[i][j] = ((dp[i][j] + dp[i - 1][j - 1]) % e + (dp[i - 2][j - 1] + dp[i - 3][j - 1]) % e) % e;
        }
    }
    scanf("%d", &n);
    for (int i = 0, j, k; i < n; i++) {
        scanf("%d %d", &j, &k);
        printf("%d\n", dp[j + 3][k]);
    }
}
