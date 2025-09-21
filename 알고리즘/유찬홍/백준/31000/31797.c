#include <stdio.h>
#include <stdlib.h>

typedef struct T {
    int v, w;
} T;

int c(const void *a, const void *b) {
    return ((T *) a)->v - ((T *) b)->v;
}

int main() {
    int n, m;
    T a[2001];
    scanf("%d %d", &n, &m);
    for (int i = 0, b, c; i < m; i++) {
        scanf("%d %d", &b, &c);
        a[i * 2] = (T){b, i};
        a[i * 2 + 1] = (T){c, i};
    }
    qsort(a, m * 2, 8, c);
    printf("%d", a[--n % (m * 2)].w + 1);
}
