#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int main() {
    int n, m, s = 0, a[1001], r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, 4, c);
    while (s < n && m) {
        if (a[s] > 0) r += a[s];
        s++, n--, m--;
    }
    printf("%d", r);
}
