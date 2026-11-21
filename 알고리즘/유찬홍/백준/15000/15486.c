#include <stdio.h>

int n, dp[1500002], t[1500001], p[1500001];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &t[i], &p[i]);
    }
    for (int i = n; i; i--) {
        dp[i] = dp[i + 1];
        if (i + t[i] - 1 <= n) {
            dp[i] = max(dp[i], dp[i + t[i]] + p[i]);
        }
    }
    printf("%d", dp[1]);
}
