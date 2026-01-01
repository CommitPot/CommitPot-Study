#include <math.h>
#include <stdio.h>
#include <string.h>

long long dp[301][301];

long long f(int n, int l) {
    if (!l) return !n;
    if (l == 1) return n == 1;
    if (dp[n][l] > -1) return dp[n][l];
    dp[n][l] = 0;
    int k = n - 1;
    for (int i = 0; i < n; i++) {
        dp[n][l] = (dp[n][l] + f(k - i, l - 1) * f(i, l - 1)) % 100030001;
        if (f(k - i, l - 1)) {
            for (int j = 0; j < l - 1; j++) {
                dp[n][l] = (dp[n][l] + f(k - i, l - 1) * f(i, j)) % 100030001;
            }
        }
        if (f(i, l - 1)) {
            for (int j = 0; j < l - 1; j++) {
                dp[n][l] = (dp[n][l] + f(k - i, j) * f(i, l - 1)) % 100030001;
            }
        }
    }
    return dp[n][l];
}

int main() {
    int n, l;
    scanf("%d %d", &n, &l);
    memset(dp, -1, sizeof(dp));
    printf("%lld", f(n, l));
}
