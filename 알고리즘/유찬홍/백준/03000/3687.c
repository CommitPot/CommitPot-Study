#include <stdio.h>

long long f(long long x) {
    long long r = 1;
    while (x) x /= 10, r *= 10;
    return r;
}

int main() {
    int n, t;
    scanf("%d", &t);
    while (t--) {
        char s[51];
        scanf("%d", &n);
        s[0] = n & 1 ? '7' : '1';
        int k = 1;
        for (int i = n & 1 ? n - 3 : n - 2; i; i -= 2, k++) s[k] = '1';
        s[k] = 0;
        long long dp[101] = {9, 9, 1, 7, 4, 2, 6, 8};
        for (int i = 8; i <= n; i++) {
            dp[i] = 1e18;
            for (int j = 2; j < 8; j++) {
                dp[i] = dp[i] < dp[i - j] * 10 + (dp[j] == 6 ? 0 : dp[j])
                            ? dp[i]
                            : dp[i - j] * 10 + (dp[j] == 6 ? 0 : dp[j]);
            }
        }
        printf("%lld %s\n", dp[n], s);
    }
}
