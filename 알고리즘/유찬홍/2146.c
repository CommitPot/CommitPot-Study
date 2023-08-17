#include <stdio.h>

typedef struct element {
    int x, y, c, b;
} element;
element queue[1000000];
int n, f = 0, r = 0, arr[101][101], vis[101][101] = {0}, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

void dfs(int x, int y, int z) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!nx || !ny || nx > n || ny > n || arr[nx][ny] == z) continue;
        if (arr[nx][ny]) {
            arr[nx][ny] = z;
            dfs(nx, ny, z);
        }
    }
}

void insert(int x, int y, int z) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (!nx || !ny || nx > n || ny > n || vis[nx][ny]) continue;
        if (!arr[nx][ny]) {
            queue[++r].x = nx;
            queue[r].y = ny;
            queue[r].c = 0;
            queue[r].b = z;
        } else {
            vis[nx][ny] = 1;
            insert(nx, ny, z);
        }
    }
}

int main() {
    int min = 100000000, l = 2, m = 2;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == 1) {
                arr[i][j] = l;
                dfs(i, j, l++);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == m) {
                vis[i][j] = 1;
                insert(i, j, m++);
                while (f < r) {
                    int x = queue[++f].x;
                    int y = queue[f].y;
                    int c = queue[f].c;
                    int b = queue[f].b;
                    if (arr[x][y] != b && arr[x][y] > 1) {
                        if (min > c) min = c;
                    }
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (!nx || !ny || nx > n || ny > n || vis[nx][ny]) continue;
                        queue[++r].x = nx;
                        queue[r].y = ny;
                        queue[r].c = c + 1;
                        queue[r].b = b;
                        vis[nx][ny] = 1;
                    }
                }
                f = r = 0;
                for (int k = 1; k <= n; k++) {
                    for (int o = 1; o <= n; o++) {
                        vis[k][o] = 0;
                    }
                }
            }
        }
    }
    printf("%d", min);
}
