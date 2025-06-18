#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct T {
    int a, b, c;
} T;

int comp(const void *a, const void *b) {
    T *A = (T *) a;
    T *B = (T *) b;
    return pow(A->a, 2) + pow(A->b, 2) < pow(B->a, 2) + pow(B->b, 2);
}

int main() {
    int n;
    T a[1001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].a, &a[i].b);
        a[i].c = i;
    }
    qsort(a, n, sizeof(T), comp);
    for (int i = 0; i < n; i++) {
        printf("%d\n", ++a[i].c);
    }
}
