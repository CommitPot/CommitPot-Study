#include <stdio.h>

int n, x, a[2097160];

int f(int v) {
    if (v >= x / 2) return 0;
    int l = f(v * 2) + a[v * 2], r = f(v * 2 + 1) + a[v * 2 + 1];
    if (l > r) {
        a[v * 2 + 1] += l - r;
        return l;
    }
    a[v * 2] += r - l;
    return r;
}

int main() {
    scanf("%d", &n);
    x = 1 << (n + 1);
    for (int i = 2; i < x; i++) scanf("%d", &a[i]);
    f(1);
    int s = 0;
    for (int i = 2; i < x; i++) s += a[i];
    printf("%d", s);
}
