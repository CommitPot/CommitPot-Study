#include <stdio.h>

int n, m, dx[] = {0, 0, 1, 1, 1, -1, -1, -1},
        dy[] = {-1, 1, 0, -1, 1, 0, 1, -1};
char arr[101][101];

void dfs(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == '.') continue;
        arr[nx][ny] = '.';
        dfs(nx, ny);
    }
}

int main() {
    int cnt = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %1c", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '#') {
                cnt++;
                arr[i][j] = '.';
                dfs(i, j);
            }
        }
    }
    printf("%d", cnt);
}
