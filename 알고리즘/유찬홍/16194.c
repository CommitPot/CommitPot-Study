#include <stdio.h>

typedef struct e {
    int x1, y1, x2, y2;
} e;

int main() {
    int n, m, f = 0, r = 1, a = 0, vis[21][21][21][21] = {0}, d[] = {0, 1, 0, -1, 0};
    char arr[21][21];
    e queue[200];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %1c", &arr[i][j]);
            if (arr[i][j] == 'o') {
                if (!a) {
                    queue[r].x1 = i;
                    queue[r].y1 = j;
                    a = 1;
                } else {
                    queue[r].x2 = i;
                    queue[r].y2 = j;
                }
            }
        }
    }
    vis[queue[1].x1][queue[1].y1][queue[1].x2][queue[1].y2] = 1;
    while (f < r) {
        int x1 = queue[++f].x1;
        int y1 = queue[f].y1;
        int x2 = queue[f].x2;
        int y2 = queue[f].y2;
        if (vis[x1][y1][x2][y2] > 11) break;
        if ((x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) || (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)) {
            if ((x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) && (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)) continue;
            else {
                printf("%d", vis[x1][y1][x2][y2] - 1);
                return 0;
            }
        }
        for (int i = 0; i < 4; i++) {
            int dx1 = x1 + d[i], dx2 = x2 + d[i];
            int dy1 = y1 + d[i + 1], dy2 = y2 + d[i + 1];
            if (arr[dx1][dy1] == '#' && arr[dx2][dy2] == '#') continue;
            if (arr[dx1][dy1] == '#') {
                dx1 = x1;
                dy1 = y1;
            }
            if (arr[dx2][dy2] == '#') {
                dx2 = x2;
                dy2 = y2;
            }
            if (vis[dx1][dy1][dx2][dy2]) continue;
            vis[dx1][dy1][dx2][dy2] = vis[x1][y1][x2][y2] + 1;
            queue[++r].x1 = dx1;
            queue[r].x2 = dx2;
            queue[r].y1 = dy1;
            queue[r].y2 = dy2;
        }
    }
    printf("-1");
}
