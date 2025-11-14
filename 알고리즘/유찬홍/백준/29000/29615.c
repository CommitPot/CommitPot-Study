#include <stdio.h>

int main() {
    int n, m, k = 0, r = 0, a[1001], b[1001] = {};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0, j; i < m; i++) scanf("%d", &j), b[j] = 1;
    while (m--) r += !b[a[k++]];
    printf("%d", r);
}
