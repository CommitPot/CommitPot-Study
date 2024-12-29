#include <stdio.h>

typedef struct e {
    int x, y;
} e;

int main() {
    int vis[302][302] = {0}, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}, w, h, f = 0, r = 0, a, b, c, d;
    char arr[302][302];
    e queue[100000];
    scanf("%d %d %d %d %d %d", &h, &w, &a, &b, &c, &d);
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            scanf(" %1c", &arr[i][j]);
        }
    }
    queue[++r].x = c;
    queue[r].y = d;
    vis[c][d] = 1;
    while (f < r) {
        int x = queue[++f].x;
        int y = queue[f].y;
        if (x == a && y == b) {
            printf("%d", vis[x][y] - 1);
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!nx || !ny || nx > h || ny > w || vis[nx][ny]) continue;
            if (arr[nx][ny] == 48) {
                queue[f].x = nx;
                queue[f--].y = ny;
                vis[nx][ny] = vis[x][y];
            } else {
                queue[++r].x = nx;
                queue[r].y = ny;
                vis[nx][ny] = vis[x][y] + 1;
            }
        }
    }
}
