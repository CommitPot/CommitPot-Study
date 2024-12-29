#include <stdio.h>

int n, m, p, arr[101][71], vis[101][71], dx[] = {-1, -1, -1, 0, 0, 1, 1, 1},
dy[] = {0, 1, -1, 1, -1, 0, 1, -1};

void dfs(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!nx || !ny || nx > n || ny > m) continue;
        if (arr[x][y] < arr[nx][ny]) p = 0;
        if (arr[nx][ny] != arr[x][y] || vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        dfs(nx, ny);
    }
}

int main() {
    int count = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] && !vis[i][j]) {
                p = 1;
                dfs(i, j);
                if (p) count++;
            }
        }
    }
    printf("%d", count);
}
