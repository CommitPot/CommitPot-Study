#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    int n, a[100][100], r[101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
        qsort(a[i], n, 4, c);
        r[i] = a[i][n / 2];
    }
    qsort(r, n, 4, c);
    printf("%d", r[n / 2]);
}
