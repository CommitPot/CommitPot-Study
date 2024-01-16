#include <stdio.h>

int n, m, c, map[101][101], vis[101][101], d[] = {0, 1, 0, -1, 0};

void dfs(int x, int y) {
    if (vis[x][y]) return;
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[i + 1];
        if (map[nx][ny] == 2) cnt++;
    }
    if (cnt) {
        vis[x][y] = 1;
        map[x][y] = 3;
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[i + 1];
            if (!vis[nx][ny] && map[nx][ny] == 1) dfs(nx, ny);
        }
    }
}

void check(int x, int y) {
    c++;
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[i + 1];
        if (map[nx][ny] == 1 && !vis[nx][ny]) {
            vis[nx][ny] = 1;
            check(nx, ny);
        }
    }
}

void rmAir(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[i + 1];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if ((!map[nx][ny] || map[nx][ny] == 2) && !vis[nx][ny]) {
            map[nx][ny] = 2;
            vis[nx][ny] = 1;
            rmAir(nx, ny);
        }
    }
}

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = 0;
            if (map[i][j] == 3) map[i][j] = 2;
        }
    }
}

int main() {
    int rs = 0, rs1 = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j]) rs1++;
        }
    }
    while (1) {
        rmAir(0, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && map[i][j] == 1) dfs(i, j);
            }
        }
        init();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 1 && !vis[i][j]) {
                    vis[i][j] = 1;
                    cnt++;
                    check(i, j);
                }
            }
        }
        if (!cnt) {
            printf("%d\n%d", ++rs, rs1);
            break;
        }
        init();
        rs++;
        rs1 = c;
        c = 0;
    }
}
