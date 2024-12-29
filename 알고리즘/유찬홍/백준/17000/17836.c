#include <stdio.h>

typedef struct element {
    int x, y, c, h;
} element;

int main() {
    element queue[100000];
    int n, m, t, min = 10001, arr[101][101], vis[101][101] = {0}, vis1[101][101] = {0};
    int f = 0, r = 0, dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    queue[++r].x = 1;
    queue[r].y = 1;
    queue[r].c = 0;
    queue[r].h = 0;
    while (f < r) {
        int x = queue[++f].x;
        int y = queue[f].y;
        int h = queue[f].h;
        int c = queue[f].c;
        if (x == n && y == m) {
            if (min > c) min = c;
        }
        if (arr[x][y] != 1 && !h && !vis[x][y]) {
            vis[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                if (x1 > 0 && x1 <= n && y1 > 0 && y1 <= m) {
                    queue[++r].x = x1;
                    queue[r].y = y1;
                    queue[r].c = c + 1;
                    if (arr[x1][y1] == 2) {
                        queue[r].h = 1;
                    } else queue[r].h = 0;
                }
            }
        } else if (h && !vis1[x][y]) {
            vis1[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                if (x1 > 0 && x1 <= n && y1 > 0 && y1 <= m) {
                    queue[++r].x = x1;
                    queue[r].y = y1;
                    queue[r].c = c + 1;
                    queue[r].h = 1;
                }
            }
        }
    }
    if (min <= t) printf("%d", min);
    else printf("Fail");
}