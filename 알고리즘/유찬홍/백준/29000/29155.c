#include <stdio.h>
#include <stdlib.h>

typedef struct T {
    int a, b;
} T;

int c(const void *a, const void *b) {
    T c = *(T *) a, d = *(T *) b;
    return c.a == d.a ? c.b - d.b : c.a - d.a;
}

int main() {
    int n, a[6], r = 0;
    T b[1001];
    scanf("%d", &n);
    for (int i = 1; i <= 5; i++) scanf("%d", &a[i]);
    for (int i = 0, c, d; i < n; i++) {
        scanf("%d %d", &c, &d);
        b[i].a = c, b[i].b = d;
    }
    qsort(b, n, 8, c);
    r = b[0].b, a[1]--;
    for (int i = 1; i < n; i++) {
        if (!a[b[i].a]) continue;
        a[b[i].a]--;
        if (b[i - 1].a != b[i].a) r += 60 + b[i].b;
        else r += b[i].b - b[i - 1].b + b[i].b;
    }
    printf("%d", r);
}
