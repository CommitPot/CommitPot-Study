#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int u, v, w;
} element;

int comp(const void *a, const void *b) {
    return ((element *) a)->w - ((element *) b)->w;
}

int n, m, arr[100001];
element a[500001];

int f(int x) {
    if (x == arr[x]) return x;
    return arr[x] = f(arr[x]);
}

void u(int x, int y) {
    x = f(x);
    y = f(y);
    arr[x > y ? x : y] = arr[x > y ? y : x];
}

int main() {
    long long int rs = 0, sum = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }
    n--;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a[i].u, &a[i].v, &a[i].w);
        sum += a[i].w;
    }
    qsort(a, m, sizeof(a[0]), comp);
    for (int i = 0; i < m; i++) {
        if (f(a[i].u) != f(a[i].v)) {
            rs += a[i].w;
            n--;
            u(a[i].u, a[i].v);
        }
    }
    printf("%lld", !n ? sum - rs : -1);
}
