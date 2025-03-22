#include <stdio.h>

int main() {
    int n, m, r = 0, a[101][101] = {};
    scanf("%d %d", &n, &m);
    for (int i = 0, b, c, d, e; i < n; i++) {
        scanf("%d %d %d %d", &b, &c, &d, &e);
        for (int j = b; j <= d; j++) {
            for (int k = c; k <= e; k++) {
                a[j][k]++;
            }
        }
    }
    for (int i = 1; i < 101; i++) {
        for (int j = 1; j < 101; j++) {
            if (a[i][j] > m) r++;
        }
    }
    printf("%d", r);
}
