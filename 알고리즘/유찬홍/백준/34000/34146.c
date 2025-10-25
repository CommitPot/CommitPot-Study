#include <stdio.h>

int main() {
    int n, m, a[10001] = {}, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0, k; j < m; j++) {
            scanf("%d", &k);
            a[k]++;
        }
    }
    for (int i = 1; i < 10001; i++) r += a[i] & 1;
    printf("%s", m & 1 ? r <= n ? "YES" : "NO" : r ? "NO" : "YES");
}
