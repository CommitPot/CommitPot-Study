#include <stdio.h>
#include <stdbool.h>

int f(int v, int p, int *a, bool *vis) {
    if (vis[v]) return v == p;
    vis[v] = 1;
    int c = f(a[v], p, a, vis);
    vis[v] = 0;
    return c;
}

int main() {
    int n, k = 0, a[101], r[101];
    bool vis[101];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        vis[i] = 1;
        if (f(a[i], i, a, vis)) r[k++] = i;
        vis[i] = 0;
    }
    printf("%d", k);
    for (int i = 0; i < k; i++) {
        printf("\n%d", r[i]);
    }
}
