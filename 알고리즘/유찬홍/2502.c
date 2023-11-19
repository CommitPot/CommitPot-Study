#include <stdio.h>

int main() {
    int d, k, dp[31] = {0, 1};
    scanf("%d %d", &d, &k);
    for (int i = 2; i <= d; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    for (int i = 2; i < k; i++) {
        int b = k - dp[d - 2] * i;
        if (b % dp[d - 1] == 0) {
            printf("%d\n%d", i, b / dp[d - 1]);
            break;
        }
    }
}
