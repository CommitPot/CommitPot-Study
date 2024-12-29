#include <stdio.h>

long long dp[21][101];

long long f(int *a, int sum, int idx) {
    if (sum < 0 || sum > 20) return 0;
    if (idx == 2) return sum == a[idx - 1];
    if (dp[sum][idx]) return dp[sum][idx];
    return dp[sum][idx] += f(a, sum + a[idx - 1], idx - 1) + f(a, sum - a[idx - 1], idx - 1);
}

int main() {
    int n, a[101];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    printf("%lld", f(a, a[n], n));
}
