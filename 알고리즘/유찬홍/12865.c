#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, k, w[101], v[101], dp[101][100001] = {0};
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= w[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    printf("%d", dp[n][k]);
}
