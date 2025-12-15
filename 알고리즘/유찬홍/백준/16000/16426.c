#include <stdio.h>

int main() {
    int n, m, a[100][101], r[100][101] = {}, d[] = {0, 1, 0, -1};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            int l = 1;
            for (int k = 0; k < 4; k++) {
                if (a[i][j] > a[i + d[k]][j + d[3 - k]]) l = 0;
            }
            r[i][j] = l;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", r[i][j]);
        }
        printf("\n");
    }
}
