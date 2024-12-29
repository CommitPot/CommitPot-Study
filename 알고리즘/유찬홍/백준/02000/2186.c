#include <stdio.h>

int n, m, k, dp[81][101][101], d[] = {0, 1, 0, -1};
char a[101][102], r[81];

int f(int x, int y, int idx) {
    if (!idx) return 1;
    if (dp[idx][x][y] > -1) return dp[idx][x][y];
    dp[idx][x][y] = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < 4; j++) {
            int nx = x + d[j] * i, ny = y + d[3 - j] * i;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] != r[idx - 1]) continue;
            dp[idx][x][y] += f(nx, ny, idx - 1);
        }
    }
    return dp[idx][x][y];
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) scanf("%s", a[i]);
    scanf("%s", r);
    int l = -1;
    while (r[++l]);
    int c = 0;
    for (int o = 0; o < l; o++) for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) dp[o][i][j] = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == r[l - 1]) c += f(i, j, l - 1);
        }
    }
    printf("%d", c);
}
