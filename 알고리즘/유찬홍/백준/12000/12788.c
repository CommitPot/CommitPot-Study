#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int main() {
    int n, m, k, a[1001], r = 0;
    scanf("%d %d %d", &n, &m, &k);
    m *= k;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, 4, c);
    for (int i = 0; m > 0; i++) {
        if (i == n) {
            r = -1;
            break;
        }
        r++;
        m -= a[i];
    }
    if (r < 0) printf("STRESS");
    else printf("%d", r);
}
