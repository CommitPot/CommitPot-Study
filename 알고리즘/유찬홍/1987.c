#include <stdio.h>

int r, c;

char arr[21][21];
int count = 0;

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1}, vis[27] = {0}, arr1[21][21] = {0};

void dfs(int x, int y, int cnt) {
    if (count < cnt) count = cnt;
    for (int i = 0; i < 4; i++) {
        int x1 = dx[i] + x;
        int y1 = dy[i] + y;
        if (x1 >= 0 && x1 < r && y1 >= 0 && y1 < c) {
            if (!vis[arr[x1][y1] - 65] && !arr1[x1][y1]) {
                vis[arr[x1][y1] - 65] = 1;
                arr1[x1][y1] = 1;
                dfs(x1, y1, cnt + 1);
                vis[arr[x1][y1] - 65] = 0;
                arr1[x1][y1] = 0;
            }
        }
    }
}

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf(" %1c", &arr[i][j]);
        }
    }
    arr1[0][0] = 1;
    vis[arr[0][0] - 65] = 1;
    dfs(0, 0, 1);
    printf("%d", count);
}
