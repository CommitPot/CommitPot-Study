#include <stdio.h>

int n, m, dp[301][301], a[301][301];

int min(int a, int b) { return a > b ? b : a; }

int v(int s, int e) {
    return 0 <= s && s < n && 0 <= e && e < m;
}

int f(int s, int e) {
    if (!v(s, e)) return 1e9;
    if (s == n - 1 && e == m - 1) return 0;
    if (dp[s][e] > -1) return dp[s][e];
    dp[s][e] = 1e9;
    for (int i = 1; i <= a[s][e]; i++) {
        dp[s][e] = min(dp[s][e], min(f(s, e + i), f(s + i, e)) + 1);
    }
    return dp[s][e];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            dp[i][j] = -1;
        }
    }
    printf("%d", f(0, 0));
}
