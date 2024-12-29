#include <stdio.h>

typedef struct element {
    int w, h;
} element;

element queue[100000];

int main() {
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    int n, m, x, y, arr[2002];
    int vis[501][501] = {0};
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for (int i = 0; i < m * 2; i += 2) {
        scanf("%d %d", &arr[i], &arr[i + 1]);
    }
    int f = 0, r = 0;
    queue[++r].h = x;
    queue[r].w = y;
    vis[x][y] = 1;
    while (f < r) {
        int w = queue[++f].w;
        int h = queue[f].h;
        for (int j = 0; j < 8; j++) {
            int nx = h + dx[j];
            int ny = w + dy[j];
            if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = vis[h][w] + 1;
            queue[++r].h = nx;
            queue[r].w = ny;
        }
    }
    for (int i = 0; i < m * 2; i += 2) {
        printf("%d ", vis[arr[i]][arr[i + 1]] - 1);
    }
}
