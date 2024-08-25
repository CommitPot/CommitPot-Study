#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int dp[70001][30], g[30];

bool f(int v, int c) {
    if (!c) return v == 15000;
    if (~dp[v][c]) return dp[v][c];
    return dp[v][c] = f(v + g[c], c - 1) | f(v - g[c], c - 1) | f(v, c - 1);
}

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &g[i]);
    memset(dp, -1, sizeof(dp));
    scanf("%d", &m);
    for (int i = 0, a; i < m; i++) {
        scanf("%d", &a);
        printf("%c ", f(a + 15000, n) ? 'Y' : 'N');
    }
}
