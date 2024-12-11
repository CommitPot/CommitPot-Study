#include <stdio.h>
#include <stdbool.h>

int n, m, d[] = {0, 1, 0, -1};
bool v[52][52];

int f(char (*a)[51], int x, int y, char c, int px, int py) {
    if (v[x][y]) return 1;
    v[x][y] = 1;
    int r = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[3 - i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || (nx == px && ny == py) || a[nx][ny] != c) continue;
        r = r || f(a, nx, ny, c, x, y);
    }
    return r;
}

int k(char (*a)[51]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; a[i][j]; j++) {
            if (v[i][j]) continue;
            if (f(a, i, j, a[i][j], 51, 51)) return 1;
        }
    }
    return 0;
}

int main() {
    char a[50][51];
    v[51][51] = 1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", a[i]);
    printf("%s", k(a) ? "Yes" : "No");
}
