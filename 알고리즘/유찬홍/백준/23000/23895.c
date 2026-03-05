#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int t, n, b, a[100001], r;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d %d", &n, &b), r = 0;
        for (int j = 0; j < n; j++) scanf("%d", &a[j]);
        qsort(a, n, 4, c);
        while (r < n && a[r] <= b) b -= a[r++];
        printf("Case #%d: %d\n", i, r);
    }
}
