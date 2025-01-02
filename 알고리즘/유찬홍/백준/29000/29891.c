#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int main() {
    int n, k, i = 0, j = 0, a[200001];
    long long r = 0;
    scanf("%d %d", &n, &k);
    for (; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > 0) j++;
    }
    qsort(a, n, 4, c);
    for (i = 0; i < j; i += k) r += a[i] * 2;
    for (i = n - 1; i >= j; i -= k) r += a[i] * -2;
    printf("%lld", r);
}
