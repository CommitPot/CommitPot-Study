#include <stdio.h>

int main() {
    int t, k, p[101], n[101], dp[10001] = {};
    dp[0] = 1;
    scanf("%d %d", &t, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &p[i], &n[i]);
    }
    for (int i = 0; i < k; i++) {
        for (int j = t; j >= 0; j--) {
            if (!dp[j]) continue;
            for (int l = 1; l <= n[i] && j + p[i] * l <= t; l++) {
                dp[j + p[i] * l] += dp[j];
            }
        }
    }
    printf("%d ", dp[t]);
}
