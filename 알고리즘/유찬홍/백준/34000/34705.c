#include <stdio.h>

int f(int *a, int l, int v, int s, int e) {
    if (l > 4) return s <= v && v <= e;
    return f(a, l + 1, v + a[l], s, e) || f(a, l + 1, v, s, e);
}

int main() {
    int t, n, m, a[5];
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < 5; i++) scanf("%d", &a[i]);
        printf("%s\n", f(a, 0, 0, n, m) ? "YES" : "NO");
    }
}
