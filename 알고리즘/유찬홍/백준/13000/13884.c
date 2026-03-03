#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int t, k, n, a[1001], b[1001];
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &k, &n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]), b[i] = a[i];
        qsort(b, n, 4, c);
        int r = 0;
        for (int i = 0, j = 0; i < n; i++) {
            if (a[i] == b[j]) r++, j++;
        }
        printf("%d %d\n", k, n - r);
    }
}
