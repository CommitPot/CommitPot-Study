#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, l, h, a[50];
    double r = 0;
    scanf("%d %d %d", &n, &l, &h);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, 4, c);
    for (int i = 0; i < l; i++) a[i] = 1e9;
    qsort(a, n, 4, c);
    for (int i = 0; i < n - h - l; i++) r += a[i];
    printf("%.10lf", r / (n - h - l));
}
