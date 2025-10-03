#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, l, a[1001], r = 1;
    double k;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, 4, c);
    k = a[0] - 0.5 + l;
    for (int i = 1; i < n; i++) {
        if (k < a[i]) k = a[i] - 0.5 + l, r++;
    }
    printf("%d", r);
}
