#include <stdio.h>

int dp[501][501];

int n, m, arr[501][501], dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

int dfs(int x, int y) {
    if (x == m && y == n) {
        return 1;
    } else if (dp[x][y] != 10001) {
        return dp[x][y];
    }
    dp[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if (x1 > 0 && y1 > 0 && x1 <= m && y1 <= n && arr[x][y] > arr[x1][y1]) {
            dp[x][y] += dfs(x1, y1);
        }
    }
    return dp[x][y];
}

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = 10001;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("%d", dfs(1, 1));
}
