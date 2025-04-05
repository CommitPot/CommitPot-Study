#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n, a[1001], dp[2][1001] = {}, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    dp[0][0] = dp[1][n - 1] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) dp[0][i] = max(dp[0][j], dp[0][i]);
        }
        dp[0][i]++;
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[i]) dp[1][i] = max(dp[1][j], dp[1][i]);
        }
        dp[1][i]++;
    }
    for (int i = 0; i < n; i++) {
        r = max(r, dp[0][i] + dp[1][i] - 1);
    }
    printf("%d", r);
}
