#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, a[100001], b[100001], r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    qsort(a, n, 4, c);
    qsort(b, n, 4, c);
    for (int i = 0, j = 0; i < n - j; i++) {
        while (a[i] >= b[i + j]) j++;
        if (i >= n - j) break;
        r++;
    }
    printf("%s", (n + 1) / 2 > r ? "NO" : "YES");
}
