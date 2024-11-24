#include <stdio.h>

int main() {
    int t, n, dp[10001] = {};
    dp[0] = 1;
    for (int i = 1; i < 4; i++) {
        for (int j = i; j < 10001; j++) {
            dp[j] += dp[j - i];
        }
    }
    scanf("%d", &t);
    while (t-- && scanf("%d", &n)) printf("%d\n", dp[n]);
}
