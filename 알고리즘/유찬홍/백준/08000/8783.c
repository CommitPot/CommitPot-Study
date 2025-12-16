#include <stdio.h>

int vis[1000][1001], d[] = {0, 1, 0, -1};
char s[1000][1001];

void f(int x, int y, int n) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[3 - i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && !vis[nx][ny] && s[nx][ny] == '.') {
            f(nx, ny, n);
        }
    }
}

int main() {
    int t, n, r = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%s", s[i]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vis[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[0][i] == '.' && !vis[0][i]) f(0, i, n);
            if (s[i][0] == '.' && !vis[i][0]) f(i, 0, n);
            if (s[n - 1][i] == '.' && !vis[n - 1][i]) f(n - 1, i, n);
            if (s[i][n - 1] == '.' && !vis[i][n - 1]) f(i, n - 1, n);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                r += !vis[i][j];
            }
        }
        printf("%d\n", r);
        r = 0;
    }
}
