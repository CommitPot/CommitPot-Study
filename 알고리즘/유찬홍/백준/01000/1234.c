#include <stdio.h>

long long dp[11][101][101];

long long p(int v) {
    return v < 2 ? 1 : v * p(v - 1);
}

long long r(int n, int l) {
    long long v = 1;
    for (int i = 0; i < l; i++) v *= p(n / l);
    return p(n) / v;
}

long long f(int n, int a, int b, int c) {
    if (a < 0 || b < 0 || c < 0) return 0;
    if (!n) return 1;
    if (dp[n][a][b]) return dp[n][a][b];
    if (n % 3 == 0) dp[n][a][b] = f(n - 1, a - n / 3, b - n / 3, c - n / 3) * r(n, 3);
    if (n % 2 == 0) {
        long long m = r(n, 2);
        dp[n][a][b] += f(n - 1, a - n / 2, b - n / 2, c) * m + f(
            n - 1, a, b - n / 2, c - n / 2) * m + f(
            n - 1, a - n / 2, b, c - n / 2) * m;
    }
    return dp[n][a][b] += f(n - 1, a - n, b, c) + f(n - 1, a, b - n, c) + f(n - 1, a, b, c - n);
}

int main() {
    int n, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    printf("%lld", f(n, a, b, c));
}
