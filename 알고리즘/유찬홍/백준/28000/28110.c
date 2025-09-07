#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int main() {
    int n, a[3001], w = 0, r = 2e9;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, 4, c);
    for (int i = 1; i < n; i++) {
        int x = (a[i - 1] + a[i]) / 2;
        if (w <= x - a[i] && a[i] != x) {
            w = x - a[i];
            r = x;
        }
    }
    printf("%d", r == 2e9 ? -1 : r);
}
