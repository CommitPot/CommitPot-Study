#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int main() {
    int t, n, r = 0, a[20001];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        qsort(a, n, 4, c);
        for (int i = 2; i < n; i += 3) r += a[i];
        printf("%d\n", r);
        r = 0;
    }
}
