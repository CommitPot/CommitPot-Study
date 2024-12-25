#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int f(int x, int y, int z, int k, int a[5][5]) {
    if (z > 2) return k;
    int d[] = {0, 1, 0, -1}, c = 1e9;
    for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[3 - i];
        if (nx < 0 || nx > 4 || ny < 0 || ny > 4 || a[nx][ny] < 0) continue;
        int b = a[nx][ny];
        a[nx][ny] = -1;
        c = min(c, f(nx, ny, z + (b == 1), k + 1, a));
        a[nx][ny] = b;
    }
    return c;
}

int main() {
    int n, m, a[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d %d", &n, &m);
    int x = a[n][m];
    a[n][m] = -1;
    int r = f(n, m, x, 0, a);
    printf("%d", r == 1e9 ? -1 : r);
}
