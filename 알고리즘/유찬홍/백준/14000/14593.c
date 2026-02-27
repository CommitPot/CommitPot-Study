#include <stdio.h>
#include <stdlib.h>

typedef struct T {
    int a, b, c, i;
} T;

int c(const void *a, const void *b) {
    T c = *(T *) a, d = *(T *) b;
    return c.a != d.a ? c.a < d.a : c.b != d.b ? c.b > d.b : c.c > d.c;
}

int main() {
    int n;
    T l[10001];
    scanf("%d", &n);
    for (int i = 0, a, b, c; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        l[i].a = a, l[i].b = b, l[i].c = c, l[i].i = i;
    }
    qsort(l, n, 16, c);
    printf("%d", ++l[0].i);
}
