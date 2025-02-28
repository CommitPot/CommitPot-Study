#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, e, a[200001], r = 0;
    scanf("%d %d", &n, &e);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, 4, c);
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] >= e) r++;
    }
    printf("%d", r + 1);
}
