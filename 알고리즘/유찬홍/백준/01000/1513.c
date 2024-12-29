#include <stdio.h>
#include <memory.h>

int a[51][51], dp[51][51][51][51];

int z(int c, int x) { return x ? x : c; }

int nk(int k, int x) { return x ? k - 1 : k; }

int f(int k, int c, int x, int y) {
    if (k < 0 || x < 1 || y < 1) return 0;
    if (x == 1 && y == 1) return dp[k][c][x][y] = (!k && !a[x][y]) || (k == 1 && a[x][y] > c);
    if (dp[k][c][x][y] > -1) return dp[k][c][x][y];
    dp[k][c][x][y] = 0;
    if (!a[x][y]) dp[k][c][x][y] += f(k, c, x - 1, y) + f(k, c, x, y - 1);
    else if (a[x][y] > c) dp[k][c][x][y] += f(k - 1, a[x][y], x, y - 1) + f(k - 1, a[x][y], x - 1, y);
    return dp[k][c][x][y] %= 1000007;
}

int main() {
    int n, m, c;
    scanf("%d %d %d", &n, &m, &c);
    for (int i = c, x, y; i >= 1; i--) {
        scanf("%d %d", &x, &y);
        a[x][y] = i;
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= c; i++) {
        printf("%d ", f(i, 0, n, m));
    }
}
