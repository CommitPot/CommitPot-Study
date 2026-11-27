#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int main() {
    int n, m, a[1001][1001];
    while (scanf("%d %d", &n, &m) == 2 && n) {
        int x = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
                x |= a[i][j];
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (!a[i][j]) continue;
                a[i][j] = min(
                              min(a[i - 1][j], a[i - 1][j - 1]),
                              a[i][j - 1]) + 1;
                x = x < a[i][j] ? a[i][j] : x;
            }
        }
        printf("%d\n", x);
    }
}
