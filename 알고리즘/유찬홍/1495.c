#include <stdio.h>

int n, s, m, v[51], dp[51][1001] = {0};

int max(int a, int b) { return a > b ? a : b; }

int func(int x, int c) {
    if (c == n) return x;
    if (dp[c][x]) return dp[c][x];
    int a = -1, b = -1;
    if (x + v[c] <= m) a = func(x + v[c], c + 1);
    if (x - v[c] >= 0) b = func(x - v[c], c + 1);
    return dp[c][x] = max(a, b);
}

int main() {
    scanf("%d %d %d", &n, &s, &m);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    printf("%d", func(s, 0));
}
