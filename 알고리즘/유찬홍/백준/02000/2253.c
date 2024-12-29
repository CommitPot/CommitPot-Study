#include <stdio.h>

int n, m, a[10001], dp[10001][151];

int min(int x, int y) { return x > y ? y : x; }

int f(int v, int w) {
    if (v > n || a[v]) return -1;
    if (v == n) return 0;
    if (dp[v][w] != 1e9) return dp[v][w];
    int x = 1e9;
    for (int i = w - 1; i <= w + 1; i++) {
        if (i < 1) continue;
        if (f(v + i, i) < 0) continue;
        x = min(x, f(v + i, i));
    }
    return dp[v][w] = x + 1;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0, b; i < m; i++) {
        scanf("%d", &b);
        a[b] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 150; j++) {
            dp[i][j] = 1e9;
        }
    }
    printf("%d", f(1, 0) == 1e9 + 1 ? -1 : f(1, 0));
}
