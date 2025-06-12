#include <stdio.h>
#include <string.h>

int a[1001], dp[1001][1001][2];

int m(int a, int b, int c) { return a > b ? c ? a : b : c ? b : a; }

int f(int s, int e, int k) {
    if (s > e) return 0;
    if (dp[s][e][k]) return dp[s][e][k];
    return dp[s][e][k] = k ? m(f(s + 1, e, 0) + a[s], f(s, e - 1, 0) + a[e], 1) : m(f(s + 1, e, 1), f(s, e - 1, 1), 0);
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        memset(dp, 0, sizeof(dp));
        printf("%d\n", f(0, n - 1, 1));
    }
}
