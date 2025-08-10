#include <stdio.h>
#include <stdlib.h>

int c(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int p[8];

void f(int n, int k, int v, int w, int *a) {
    if (v == w) {
        for (int i = 0; i < w; i++) {
            printf("%d ", p[i]);
        }
        printf("\n");
        return;
    }
    for (int i = k; i < n; i++) {
        if (i && a[i] == a[i - 1]) continue;
        p[v] = a[i];
        f(n, i, v + 1, w, a);
    }
}

int main() {
    int n, m, a[8];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, 4, c);
    f(n, 0, 0, m, a);
}
