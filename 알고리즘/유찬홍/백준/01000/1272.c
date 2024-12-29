#include <stdio.h>

int dp[1001][1001][2], w[1001], l[1001][2001], q[1001];

int min(int a, int b) { return a < b ? a : b; }

int f(int v, int s, int b) {
    if (dp[v][s][b]) return dp[v][s][b];
    for (int i = 0; i < q[v]; i++) {
        if (w[l[v][i]] <= w[v]) continue;
        dp[v][s][b] += min(f(l[v][i], b ? s : v, 0), f(l[v][i], b ? s : v, 1));
    }
    return dp[v][s][b] += w[v] - (b ? w[s] : 0);
}

int main() {
    int n, r;
    scanf("%d %d", &n, &r);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1, a, b; i < n; i++) {
        scanf("%d %d", &a, &b);
        l[a][q[a]++] = b;
        l[b][q[b]++] = a;
    }
    printf("%d", f(r, 1, 0));
}
