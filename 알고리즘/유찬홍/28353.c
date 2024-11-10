#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, k, r = 0, a[5001];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, 4, comp);
    int s = 0, e = n - 1;
    while (s < e) {
        if (a[s] + a[e] > k) e--;
        else r++, s++, e--;
    }
    printf("%d", r);
}
