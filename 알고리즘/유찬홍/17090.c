#include <stdio.h>

int n, m, dp[501][501], vis[501][501];
char arr[501][501];

int dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return 1;
    if (dp[x][y] || vis[x][y]) return dp[x][y];
    vis[x][y] = 1;
    switch (arr[x][y]) {
        case 'U':
            dp[x][y] = dfs(x - 1, y);
            break;
        case 'D':
            dp[x][y] = dfs(x + 1, y);
            break;
        case 'L':
            dp[x][y] = dfs(x, y - 1);
            break;
        case 'R':
            dp[x][y] = dfs(x, y + 1);
            break;
    }
    return dp[x][y];
}

int main() {
    int rs = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dfs(i, j)) rs++;
        }
    }
    printf("%d", rs);
}
