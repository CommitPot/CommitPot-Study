#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, m, a[1000001], b[1000001], d[2], r[2] = {1, 1};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    qsort(a, n, 4, c);
    qsort(b, m, 4, c);
    d[0] = a[0] + 100;
    d[1] = b[0] + 360;
    for (int i = 1; i < n; i++) {
        if (d[0] > a[i]) continue;
        d[0] = a[i] + 100;
        r[0]++;
    }
    for (int i = 1; i < m; i++) {
        if (d[1] > b[i]) continue;
        d[1] = b[i] + 360;
        r[1]++;
    }
    printf("%d %d", r[0], r[1]);
}
