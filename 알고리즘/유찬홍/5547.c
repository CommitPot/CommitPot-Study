#include <stdio.h>
#include <stdbool.h>

int w, h, dx[] = {-1, 0, 1, 1, 0, -1},
        dy[][6] = {{0,  -1, 0,  1, 1, 1},
                   {-1, -1, -1, 0, 1, 0}};
bool vis[100][100], a[100][100];

int f(int x, int y) {
    int c = 6;
    for (int i = 0; i < 6; i++) {
        int nx = x + dx[i], ny = y + dy[x % 2][i];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w || !a[nx][ny]) continue;
        c--;
        if (vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        c += f(nx, ny);
    }
    return c;
}

int z(int x, int y) {
    int c = 0, d = 0;
    for (int i = 0; i < 6; i++) {
        int nx = x + dx[i], ny = y + dy[x % 2][i];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
            d = 1;
            continue;
        }
        if (a[nx][ny]) c++;
        if (a[nx][ny] || vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        int k = z(nx, ny);
        if (k > 0) c += k;
        else d = 1;
    }
    return d ? -1 : c;
}

int main() {
    scanf("%d %d", &w, &h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int r = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] && !vis[i][j]) {
                vis[i][j] = 1;
                r += f(i, j);
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!a[i][j] && !vis[i][j]) {
                vis[i][j] = 1;
                int x = z(i, j);
                if (x < 0) continue;
                r -= x;
            }
        }
    }
    printf("%d", r);
}
