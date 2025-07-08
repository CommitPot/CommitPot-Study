#include <stdio.h>

int main() {
    int n, m, r = 0, a[500][500];
    long long s = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            int k = a[i][j];
            while (k) {
                s += k % 10 == 9;
                k /= 10;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int v = 0;
        for (int j = 0; j < m; j++) {
            int l = a[i][j];
            while (l) {
                v += l % 10 == 9;
                l /= 10;
            }
        }
        r = r < v ? v : r;
    }
    for (int i = 0; i < m; i++) {
        int v = 0;
        for (int j = 0; j < n; j++) {
            int l = a[j][i];
            while (l) {
                v += l % 10 == 9;
                l /= 10;
            }
        }
        r = r < v ? v : r;
    }
    printf("%lld", s - r);
}
