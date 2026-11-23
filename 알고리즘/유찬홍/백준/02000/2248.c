#include <stdio.h>

int m(int a, int b) { return a > b ? b : a; }

int main() {
    int n, l, dp[32][32] = {};
    long long x;
    scanf("%d %d %lld", &n, &l, &x);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= m(i, l); j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
    while (n--) {
        long long r = 0;
        for (int j = m(n, l); j >= 0; j--) r += dp[n][j];
        printf("%d", x > r ? 1 : 0);
        if (x > r) x -= r, l--;
    }
}
