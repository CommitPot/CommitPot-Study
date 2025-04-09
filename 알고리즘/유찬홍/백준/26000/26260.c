#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int f(int *a, int k, int n) {
    if (n == 1) return a[k];
    n /= 2;
    printf("%d ", f(a, k - n, n));
    printf("%d ", f(a, k + n, n));
    return a[k];
}

int main() {
    int n, a[131100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &a[n]);
    qsort(a, n + 1, 4, c);
    printf("%d", f(a, (n + 1) / 2, (n + 1) / 2));
}
