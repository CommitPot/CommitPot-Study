#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int main() {
    int t, j, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &j, &n);
        int d[1001];
        for (int i = 0, a, b; i < n; i++) {
            scanf("%d %d", &a, &b);
            d[i] = a * b;
        }
        qsort(d, n, 4, c);
        int r = 0, w = 0;
        while (w < j) w += d[r++];
        printf("%d\n", r);
    }
}
