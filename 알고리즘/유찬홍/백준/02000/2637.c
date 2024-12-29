#include <stdio.h>

int n, m, a[101][101], dp[101], e[101], l[101][201], q[101];

int f(int x, int p, int b) {
    if (!e[x]) return !!(a[p][x] += b);
    if (dp[x]) return dp[x];
    for (int i = 0; i < q[x]; i++) {
        dp[x] += f(l[x][i], x, l[x][i + 100]) * l[x][i + 100];
        for (int j = 1; j <= n; j++) if (!e[j]) a[x][j] += a[l[x][i]][j] * l[x][i + 100];
    }
    return dp[x];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1, b, c, d; i <= m; i++) {
        scanf("%d %d %d", &b, &c, &d);
        e[b]++;
        l[b][q[b]] = c;
        l[b][++q[b] + 99] = d;
    }
    f(n, 0, 0);
    for (int i = 1; i <= n; i++) {
        if (!e[i]) printf("%d %d\n", i, a[n][i]);
    }
}
