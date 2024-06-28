#include <stdio.h>

int main() {
    int n, m, a, b, e[101][101] = {}, f[101][101] = {};
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for (int i = 0, c, d; i < a; i++) {
        scanf("%d %d", &c, &d);
        for (int j = c + 1; j <= n; j++) {
            for (int k = d - 1; k >= 1; k--) {
                f[j][k] = 1;
            }
        }
        for (int j = c - 1; j >= 1; j--) {
            for (int k = d + 1; k <= m; k++) {
                f[j][k] = 1;
            }
        }
    }
    for (int i = 0, c, d; i < b; i++) {
        scanf("%d %d", &c, &d);
        f[c][d] = 2;
    }
    e[1][1] = f[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (f[i][j]) continue;
            f[i][j] = 1;
            if (i == 1) e[i][j] += e[i][j - 1];
            else if (j == 1) e[i][j] += e[i - 1][j];
            else e[i][j] += e[i - 1][j] + e[i][j - 1];
        }
    }
    printf("%d", e[n][m]);
}
