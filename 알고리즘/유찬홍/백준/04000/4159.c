#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, r = 1, a[1423];
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        qsort(a, n, 4, c);
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1] + 200) r = 0;
        }
        if (a[0] || a[n - 1] < 1322) r = 0;
        printf("%sPOSSIBLE\n", r ? "" : "IM");
        r = 1;
    }
}
