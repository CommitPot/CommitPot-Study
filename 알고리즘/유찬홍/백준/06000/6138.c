#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return abs(*(int *) a) - abs(*(int *) b);
}

int main() {
    int t, n, a[50001], r = 0;
    scanf("%d %d", &t, &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, 4, c);
    for (int i = 0, j = 0; i < n; i++) {
        int x = abs(a[i] - j);
        if (t >= x) t -= x, j = a[i], r++;
        else break;
    }
    printf("%d", r);
}
