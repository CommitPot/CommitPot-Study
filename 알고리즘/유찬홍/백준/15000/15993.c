#include <stdio.h>

int main() {
    int t, n, e = 1e9 + 9;
    int dp[100001][2] = {1, 0, 1, 1, 2, 2};
    for (int i = 3; i < 100000; i++) {
        dp[i][0] = (int) (((long long) (dp[i - 1][1] + dp[i - 2][1]) + dp[i - 3][1]) % e);
        dp[i][1] = (int) (((long long) (dp[i - 1][0] + dp[i - 2][0]) + dp[i - 3][0]) % e);
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d %d\n", dp[n - 1][0], dp[n - 1][1]);
    }
}
