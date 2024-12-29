#include <stdio.h>

#define INF 100000000

typedef struct element {
    int x, y, cnt;
} element;


element queue[1000000];

int main() {
    int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int dy[] = {1, 1, 1, 0, -1, -1, -1, 0};
    int f = 500000, r = 500000, h, w, a, b, vis[501][501] = {0};
    char arr[501][501];
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf(" %1c", &arr[i][j]);
            vis[i][j] = INF;
            if (arr[i][j] == 'K') {
                queue[++r].x = i;
                queue[r].y = j;
                queue[r].cnt = 0;
            }
            if (arr[i][j] == '*') {
                a = i;
                b = j;
            }
        }
    }
    while (f < r) {
        int x = queue[++f].x;
        int y = queue[f].y;
        int cnt = queue[f].cnt;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (arr[nx][ny] == '#') continue;
            if (i < 3 && vis[nx][ny] > cnt) {
                queue[f].x = nx;
                queue[f].y = ny;
                queue[f--].cnt = cnt;
                vis[nx][ny] = cnt;
            }
            if (i >= 3 && vis[nx][ny] > cnt + 1) {
                queue[++r].x = nx;
                queue[r].y = ny;
                queue[r].cnt = cnt + 1;
                vis[nx][ny] = cnt + 1;

            }
        }
    }
    if (vis[a][b] == INF) printf("-1");
    else printf("%d", vis[a][b]);
}
