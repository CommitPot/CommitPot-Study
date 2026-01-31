#include <stdio.h>

int f(int *a, int m, int x, int y, int d, int r) {
    if (!a[x * m + y]) a[x * m + y] = 2, r++;
    int b[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}, c = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + b[i][0], ny = y + b[i][1];
        if (!a[nx * m + ny]) c = 1;
    }
    if (c) {
        d = (d + 4 - 1) % 4;
        int nx = x + b[d][0], ny = y + b[d][1];
        if (!a[nx * m + ny]) return f(a, m, nx, ny, d, r);
        return f(a, m, x, y, d, r);
    }
    int nx = x + b[(d + 6) % 4][0], ny = y + b[(d + 6) % 4][1];
    return a[nx * m + ny] == 1 ? r : f(a, m, nx, ny, d, r);
}

int main() {
    int n, m, x, y, d, a[2500];
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &d);
    for (int i = 0; i < n * m; i++) scanf("%d", &a[i]);
    printf("%d", f(a, m, x, y, d, 0));
}
