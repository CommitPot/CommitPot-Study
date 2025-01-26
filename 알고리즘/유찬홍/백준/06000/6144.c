#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, m, w[3402], v[3402], dp[2][12881] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j >= w[i]) dp[i & 1][j] = max(dp[~i & 1][j], dp[~i & 1][j - w[i]] + v[i]);
            else dp[i & 1][j] = dp[~i & 1][j];
        }
    }
    printf("%d", dp[~n & 1][m]);
}
