#include <stdio.h>
#include <stdlib.h>

typedef struct a {
    int p, a;
} c;

int comp(const void *a, const void *b) {
    c a1 = *(c *) a;
    c b1 = *(c *) b;
    if (a1.a > b1.a) return 1;
    else if (a1.a == b1.a) {
        if (a1.p > b1.p) return 1;
        else return -1;
    }
    return -1;
}

int comp1(const void *a, const void *b) {
    return (((c *) a)->p - ((c *) b)->p);
}

int main() {
    int n;
    c arr[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].a);
        arr[i].p = i;
    }
    qsort(arr, n, sizeof(arr[0]), comp);
    for (int i = 0; i < n; i++) {
        arr[i].a = i;
    }
    qsort(arr, n, sizeof(arr[0]), comp1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i].a);
    }
    return 0;
}