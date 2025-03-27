#include <stdio.h>

int main() {
    int t, n, dp[1000001] = {};
    for (int i = 1; i < 1000001; i++) {
        for (int j = 1; !dp[i] && j * j <= i; j++) {
            dp[i] |= !dp[i - j * j];
        }
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%s\n", dp[n] ? "koosaga" : "cubelover");
    }
}
