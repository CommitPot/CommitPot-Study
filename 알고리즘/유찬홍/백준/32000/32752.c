#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, l, r, a[100001], s = 1;
    scanf("%d %d %d", &n, &l, &r);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a + l - 1, r - l + 1, 4, c);
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) s = 0;
    }
    printf("%d", s);
}
