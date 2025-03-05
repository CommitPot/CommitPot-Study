#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, s, a[20001], v = 0;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, 4, c);
    for (int i = 0; a[i] + a[i + 1] <= s; i++) {
        int l = i + 1, r = n;
        while (l < r) {
            int m = (l + r) / 2;
            if (a[i] + a[m] > s) r = m;
            else l = m + 1;
        }
        v += r - 1 - i;
    }
    printf("%d", v);
}
