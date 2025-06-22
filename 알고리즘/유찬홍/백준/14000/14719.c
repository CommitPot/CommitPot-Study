#include <stdio.h>

int main() {
    int n, m, a[501][501] = {}, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0, j; i < m; i++) {
        scanf("%d", &j);
        for (int k = 0; k < j; k++) a[k][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (!a[i][j] && j < m) j++;
        for (int k = j + 1; k < m; k++) {
            if (a[i][k]) {
                r += k - j - 1;
                j = k;
            }
        }
    }
    printf("%d", r);
}
