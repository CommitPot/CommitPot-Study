#include <stdio.h>

int main() {
    int t, n, dp[2001] = {1,};
    for (int i = 2000; i >= 0; i--) {
        for (int j = 2000; j >= i + 1; j--) {
            dp[j] = (dp[j] + dp[j - i - 1]) % 100999;
        }
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
}
