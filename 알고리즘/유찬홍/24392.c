#include <stdio.h>

int main() {
    int n, m, s = 0, e = 1e9 + 7, dp[2][1001] = {0};
    char a[2002];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", a);
        if (!i) {
            for (int j = 0, k = 0; j < m * 2 - 1; j += 2, k++) {
                dp[0][k] = a[j] - 48;
            }
            continue;
        }
        for (int j = 0, k = 0; k < m; j += 2, k++) {
            if (a[j] == 49) {
                if (!k) {
                    dp[1][k] = (dp[0][k] + dp[0][k + 1]) % e;
                } else if (k == m - 1) {
                    dp[1][k] = (dp[0][k] + dp[0][k - 1]) % e;
                } else {
                    dp[1][k] = ((dp[0][k - 1] + dp[0][k]) % e + dp[0][k + 1]) % e;
                }
            }
        }
        for (int j = 0; j < m; j++) {
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }
    for (int j = 0; j < m; j++) {
        s = (s + dp[0][j]) % e;
    }
    printf("%d", s);
}
