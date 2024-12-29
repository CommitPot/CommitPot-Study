#include <stdio.h>

typedef struct element {
    int x, y, c;
} element;

element queue[2000000];
int n, m, f = 0, r = 0, arr[1001][1001], vis[1001][1001][2] = {0};

int main() {
    int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    queue[++r].x = 1;
    queue[r].y = 1;
    queue[r].c = 0;
    vis[1][1][0] = 1;
    while (f < r) {
        int x = queue[++f].x;
        int y = queue[f].y;
        int c = queue[f].c;
        if (x == n && y == m) {
            printf("%d", vis[x][y][c]);
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int d = arr[nx][ny] ? 1 : 0;
            if (c & d) continue;
            if (nx > 0 && nx <= n && ny > 0 && ny <= m && !vis[nx][ny][c + d]) {
                queue[++r].x = nx;
                queue[r].y = ny;
                queue[r].c = c + d;
                vis[nx][ny][c + d] += vis[x][y][c] + 1;
            }
        }
    }
    printf("-1");
}
