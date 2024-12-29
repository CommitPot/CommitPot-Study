#include <stdio.h>

typedef struct element {
    int x, y;
} element;
int n, arr[51][51], vis[51][51] = {0};
element deque[10000];

int main() {
    int f = 5000, r = 5000, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    deque[++r].x = 1;
    deque[r].y = 1;
    vis[1][1] = 1;
    while (f < r) {
        int x = deque[++f].x;
        int y = deque[f].y;
        if (x == n && y == n) {
            printf("%d", vis[n][n] - 1);
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!nx || !ny || nx > n || ny > n) continue;
            if (!vis[nx][ny]) {
                if (arr[nx][ny]) {
                    deque[f].x = nx;
                    deque[f--].y = ny;
                    vis[nx][ny] = vis[x][y];
                } else {
                    deque[++r].x = nx;
                    deque[r].y = ny;
                    vis[nx][ny] = vis[x][y] + 1;
                }
            }
        }
    }
}
