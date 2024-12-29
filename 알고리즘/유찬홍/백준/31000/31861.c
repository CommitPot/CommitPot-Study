#include <stdio.h>

int main() {
    int n, m, r = 0, d = 1e9 + 7, dp[2][26] = {};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < 26; i++) dp[0][i] = 1;
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                if (k <= j - n || k >= j + n) dp[1][j] = (dp[1][j] + dp[0][k]) % d;
            }
        }
        for (int j = 0; j < 26; j++) dp[0][j] = dp[1][j], dp[1][j] = 0;
    }
    for (int i = 0; i < 26; i++) r = (r + dp[0][i]) % d;
    printf("%d", r);
}
