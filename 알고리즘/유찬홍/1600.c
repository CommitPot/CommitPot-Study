#include <stdio.h>

typedef struct element {
    int x, y, c, kC;
} element;

int main() {
    element queue[2000000];
    int k, w, h, f = 0, r = 0, arr[201][201], vis[201][201][31] = {0};
    int dx1[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dx[] = {0, 0, 1, -1};
    int dy1[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    int dy[] = {1, -1, 0, 0};
    scanf("%d %d %d", &k, &w, &h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    queue[++r].x = 0;
    queue[r].y = 0;
    queue[r].c = 0;
    queue[r].kC = 0;
    vis[0][0][0] = 1;
    while (f < r) {
        int x = queue[++f].x;
        int y = queue[f].y;
        int c = queue[f].c;
        int kC = queue[f].kC;
        if (x == h - 1 && y == w - 1) {
            printf("%d", c);
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (vis[nx][ny][kC] || arr[nx][ny]) continue;
            vis[nx][ny][kC] = 1;
            queue[++r].x = nx;
            queue[r].y = ny;
            queue[r].c = c + 1;
            queue[r].kC = kC;
        }
        if (kC >= k) continue;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx1[i];
            int ny = y + dy1[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (vis[nx][ny][kC + 1]) continue;
            if (arr[nx][ny]) continue;
            vis[nx][ny][kC + 1] = 1;
            queue[++r].x = nx;
            queue[r].y = ny;
            queue[r].c = c + 1;
            queue[r].kC = kC + 1;
        }
    }
    printf("-1");
}
