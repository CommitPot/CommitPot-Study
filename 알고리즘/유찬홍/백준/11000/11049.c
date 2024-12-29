#include <stdio.h>

#define max 2147483647
int n, r[501], c[501], dp[501][501];

int f(int s, int e) {
    if (dp[s][e]) return dp[s][e];
    if (s + 1 == e) return dp[s][e] = r[s] * c[s] * c[e];
    dp[s][e] = max;
    for (int i = s; i < e; i++) {
        int x = 0, y = 0, d = 0;
        if (s == i) x = r[s] * c[s] * c[e];
        else x = f(s, i);
        if (i + 1 == e) y = r[e] * c[e] * r[s];
        else y = f(i + 1, e);
        if (s != i && i + 1 != e) d += r[s] * c[i] * c[e];
        dp[s][e] = dp[s][e] < x + y + d ? dp[s][e] : x + y + d;
    }
    return dp[s][e];
}


int main() {
    scanf("%d", &n);
    for (int i = 1, a, b; i <= n; i++) {
        scanf("%d %d", &a, &b);
        r[i] = a, c[i] = b;
    }
    printf("%d", f(1, n) == max ? 0 : dp[1][n]);
}
