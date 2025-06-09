#include <stdio.h>

int n, m, a[101], dp[101][101];

int min(int a, int b) { return a < b ? a : b; }

int f(int v, int c) {
    if (c < 0) return 1e9;
    if (v > n) return 0;
    if (a[v]) return f(v + 1, c);
    if (dp[v][c]) return dp[v][c];
    return dp[v][c] = min(min(f(v + 1, c) + 10000, f(v + 1, c - 3)),
                          min(f(v + 3, c + 1) + 25000, f(v + 5, c + 2) + 37000));
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0, j; i < m; i++) {
        scanf("%d", &j);
        a[j] = 1;
    }
    printf("%d", f(1, 0));
}
