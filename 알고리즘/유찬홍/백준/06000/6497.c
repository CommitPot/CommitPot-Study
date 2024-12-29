#include <stdio.h>
#include <stdlib.h>

typedef struct e {
    int u, v, w;
} e;

e arr[200001];
int v[200001];

int comp(const void *a, const void *b) {
    return ((e *) a)->w - ((e *) b)->w;
}

int f(int x) {
    if (v[x] == x) return x;
    return v[x] = f(v[x]);
}

int u(int x, int y) {
    x = f(x);
    y = f(y);
    if (x == y) return 0;
    v[x < y ? x : y] = x > y ? x : y;
    return 1;
}

int main() {
    int n, m, c = 0;
    scanf("%d %d", &m, &n);
    while (m || n) {
        for (int i = 0; i <= m; i++) v[i] = i;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &arr[i].u, &arr[i].v, &arr[i].w);
        }
        qsort(arr, n, sizeof(arr[0]), comp);
        for (int i = 0; i < n; i++) {
            if (!u(arr[i].u, arr[i].v)) c += arr[i].w;
        }
        printf("%d\n", c);
        c = 0;
        scanf("%d %d", &m, &n);
    }
}
