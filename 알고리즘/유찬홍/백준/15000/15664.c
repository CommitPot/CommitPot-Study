#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int v[8];

void f(int p, int n, int m, int *a, int l) {
    if (m == l) {
        for (int i = 0; i < m; i++) {
            printf("%d ", v[i]);
        }
        printf("\n");
        return;
    }
    int k = 0;
    for (int i = p; i < n; i++) {
        if (k == a[i]) continue;
        v[l++] = a[i];
        f(i + 1, n, m, a, l--);
        k = a[i];
    }
}

int main() {
    int n, m, a[8];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, 4, c);
    f(0, n, m, a, 0);
}
