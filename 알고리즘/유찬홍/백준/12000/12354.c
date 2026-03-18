#include <stdio.h>

int main() {
    int t, n, a[2][51];
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++) scanf("%d", &a[0][j]), a[1][j] = 0;
        for (int j = 0, l; j < n; j++) {
            l = a[0][j];
            for (int k = 0; k < j; k++) {
                if (l > a[0][k]) a[1][j] = a[1][j] < a[1][k] ? a[1][k] : a[1][j];
            }
            a[1][j]++;
        }
        printf("Case #%d: %d\n", i + 1, n - a[1][n - 1]);
    }
}
