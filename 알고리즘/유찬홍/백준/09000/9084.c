#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int a = 0; a < t; a++) {
        int n, m, w[21], dp[10001] = {0};
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &w[i]);
        }
        scanf("%d", &m);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                if (j >= w[i]) dp[j] += dp[j - w[i]];
            }
        }
        printf("%d\n", dp[m]);
    }
}
