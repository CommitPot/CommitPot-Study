#include <stdio.h>
#include <memory.h>

int n, m, vis[50][50], dp[50][50], d[] = {0, 1, 0, -1};
char a[50][51];

int max(int x, int y) { return x > y ? x : y; }

int f(int l, int x, int y) {
    if (a[x][y] == 'H') return 0;
    if (vis[x][y] == 1) return 1e9;
    if (dp[x][y] > -1) return dp[x][y];
    dp[x][y] = 0;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i] * (a[x][y] - 48), ny = y + d[3 - i] * (a[x][y] - 48);
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            dp[x][y] = max(dp[x][y], 1);
            continue;
        }
        if (dp[nx][ny] >= 1e9) continue;
        dp[x][y] = max(dp[x][y], f(l + 1, nx, ny) + 1);
    }
    vis[x][y]--;
    return dp[x][y];
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", a[i]);
    memset(dp, -1, sizeof(dp));
    printf("%d", f(0, 0, 0) >= 1e9 ? -1 : f(0, 0, 0));
}
