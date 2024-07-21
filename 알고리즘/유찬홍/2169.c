#include <stdio.h>

int n, m, dp[1001][1001][3], a[1001][1001];

int max(int q, int w) { return q > w ? q : w; }

int f(int x, int y, int z, int p);

int k(int x, int y, int z, int p) { return (!z && p == 1) || (z == 1 && !p) ? -2e9 : f(x, y, z, p); }

int f(int x, int y, int z, int p) {
    if (x < 1 || y < 1 || y > m) return -2e9;
    if (x == 1 && y == 1) return dp[x][y][z] = a[1][1];
    if (dp[x][y][z] > -2e9) return dp[x][y][z];
    dp[x][y][z] = a[x][y];
    int v = max(k(x, y - 1, 0, z), max(k(x, y + 1, 1, z), k(x - 1, y, 2, z)));
    return dp[x][y][z] += v;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = -2e9;
            }
        }
    }
    int x = max(f(n, m - 1, 0, 0), f(n - 1, m, 2, 0));
    printf("%d", (x == -2e9 ? 0 : x) + a[n][m]);
}
