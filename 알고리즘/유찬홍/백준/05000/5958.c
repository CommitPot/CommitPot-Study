#include <stdio.h>

int n, r = 0;
char a[1002][1003];

void f(int x, int y) {
    for (int i = 0, d[] = {0, 1, 0, -1}; i < 4; i++) {
        int nx = x + d[i], ny = y + d[3 - i];
        if (!nx || nx > n || !ny || ny > n || a[nx][ny] == '.') continue;
        a[nx][ny] = '.';
        f(nx, ny);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s", &a[i][1]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == '*') a[i][j] = '.', f(i, j), r++;
        }
    }
    printf("%d", r);
}
