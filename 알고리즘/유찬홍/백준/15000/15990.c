#include <stdio.h>

int main() {
    int t, n, m = 1e9 + 9, dp[100000][3] = {{1, 0, 0},
                                            {0, 1, 0},
                                            {1, 1, 1}};
    for (int i = 3; i < 100000; i++) {
        dp[i][0] += (dp[i - 1][1] + dp[i - 1][2]) % m;
        dp[i][1] += (dp[i - 2][0] + dp[i - 2][2]) % m;
        dp[i][2] += (dp[i - 3][0] + dp[i - 3][1]) % m;
    }
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        n--;
        printf("%d\n", ((dp[n][0] + dp[n][1]) % m + dp[n][2]) % m);
    }
}
