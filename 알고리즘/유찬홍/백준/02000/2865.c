#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(double *) a < *(double *) b;
}

int main() {
    int n, m, k;
    double a[101] = {}, s;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0, j; i < n * m; i++) {
        scanf("%d %lf", &j, &s);
        j--;
        a[j] = a[j] < s ? s : a[j];
    }
    qsort(a, n, 8, c);
    s = 0;
    for (int i = 0; i < k; i++) s += a[i];
    printf("%.1lf", s);
}
