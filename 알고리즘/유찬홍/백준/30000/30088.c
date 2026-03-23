#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, m, a[1001];
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0, k = 0; i < n; i++) {
        scanf("%d", &m);
        for (int j = 0, p; j < m; j++) {
            scanf("%d", &p), k += p;
        }
        a[i] = k;
        k = 0;
    }
    qsort(a, n, 4, c);
    for (int i = 0; i < n; i++) r += a[i] * (n - i);
    printf("%lld", r);
}
