#include <stdio.h>

int main() {
    int n, m, k, p[301][301];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &p[i][j]);
        }
    }
    scanf("%d", &k);
    while (k--) {
        int a, b, c, d, s = 0;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for (int i = a; i <= c; i++) {
            for (int j = b; j <= d; j++) {
                s += p[i][j];
            }
        }
        printf("%d\n", s);
    }
}
