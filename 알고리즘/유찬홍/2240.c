#include <stdio.h>

int l[1001], dp[1001][31][2];

int max(int a, int b) { return a > b ? a : b; }

int f(int t, int w, int v) {
    if (w < 0) return -1;
    if (!t) return !v ? 0 : -1;
    if (dp[t][w][v]) return dp[t][w][v];
    return dp[t][w][v] = max(f(t - 1, w - 1, !v), f(t - 1, w, v)) + (l[t] - 1 == v);
}

int main() {
    int t, w;
    scanf("%d %d", &t, &w);
    for (int i = 1; i <= t; i++) scanf("%d", &l[i]);
    printf("%d", max(f(t, w, 0), f(t, w, 1)));
}
