#include <stdio.h>

int main() {
    int n, m, a[101] = {}, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0, j; i < m; i++) scanf("%d", &j), a[j] = 1;
    for (int i = 1, j = 0; i <= n; i++) {
        if (a[i]) continue;
        if (j && 3 >= i - j) r += 2 * (i - j);
        else r += 7;
        j = i;
    }
    printf("%d", r);
}
