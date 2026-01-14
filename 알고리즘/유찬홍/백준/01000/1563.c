#include <stdio.h>
#include <string.h>

int dp[1001][3][3][2];

int f(int n, int a, int b, int c) {
    if (c > 1) return 0;
    if (!n) return 1;
    if (dp[n][a][b][c] != -1) return dp[n][a][b][c];
    dp[n][a][b][c] = 0;
    for (int i = 0; i < 3; i++) {
        if (a == 1 && b == 1 && i == 1) continue;
        dp[n][a][b][c] = (dp[n][a][b][c] + f(n - 1, i, a, c + (i == 2))) % 1000000;
    }
    return dp[n][a][b][c];
}

int main() {
    int n;
    scanf("%d", &n);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(n, 0, 0, 0));
}
