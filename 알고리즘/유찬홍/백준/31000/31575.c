#include <stdio.h>

int n, m;
char a[300][301];

void d(int x, int y) {
    a[x][y] = 48;
    if (y + 1 < m && a[x][y + 1] == 49) d(x, y + 1);
    if (x + 1 < n && a[x + 1][y] == 49) d(x + 1, y);
}

int main() {
    char b[600];
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", b);
        for (int j = 0, k = 0; k < m; j += 2, k++) {
            a[i][k] = b[j];
        }
    }
    d(0, 0);
    printf("%s", a[n - 1][m - 1] == 49 ? "No" : "Yes");
}
