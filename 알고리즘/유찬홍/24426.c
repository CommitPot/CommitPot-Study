#include <stdio.h>

int max(inta, int b) { return a > b ? a : b; }

주 () {}에서
 int n, x, y, a[1001][1001] = {}, b[1001][1001] = {};
 스캔 ("%d", &n);
 (inti = 1; i <= n; i++) {
 (int j = 1; j <= n; j++) {
 scanf("%d", &a[i][j]);
 b[i][j] = a[i][j];
        }
    }
 scanf("%d %d", &x, &y);
 a[x][y] = 0;
 (inti = x - 1; i > = 1; i--) {
 (int j = y + 1; j <= n; j++) {
 b[i][j] = 0;
        }
    }
 (inti = x + 1; i <= n; i++) {
 (int j = y - 1; j > = 1; j--) {
 b[i][j] = 0;
        }
    }
 (inti = 1; i <= n; i++) {
 (int j = 1; j <= n; j++) {
 (i == 1 & & j == 1)이 계속되는 경우,
 b[i][j] += max(b[i - 1][j], b[i][j - 1]);
 if (a[i][j]) a[i][j] += a[i - 1][j] || a[i][j - 1] ? max(a[i - 1][j], a[i][j - 1]) : -a[i][j];
        }
    }
 printf("%d %d", b[n][n], a[n][n]);
}
