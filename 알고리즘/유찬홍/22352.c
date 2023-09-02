#include <stdio.h>

int n, m, arr[31][31], arr1[31][31], dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int v, int rs) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] != v) continue;
        arr[nx][ny] = rs;
        dfs(nx, ny, v, rs);
    }
}

int main() {
    int sw = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                scanf("%d", !i ? &arr[j][k] : &arr1[j][k]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != arr1[i][j] && !sw) {
                dfs(i, j, arr[i][j], arr1[i][j]);
                arr[i][j] = arr1[i][j];
                sw = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != arr1[i][j]) {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
}
