#include <stdio.h>

int main() {
    int t, n, m, a[100][101];
    scanf("%d", &t);
    while (t--) {
        int r = 0;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (!a[i][j]) continue;
                int k = i;
                while (k < n - 1 && !a[k + 1][j]) k++, r++;
                a[i][j] = 0;
                a[k][j] = 1;
            }
        }
        printf("%d\n", r);
    }
}
