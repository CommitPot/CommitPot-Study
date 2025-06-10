#include <math.h>
#include <stdio.h>

int f(int *st, int k, int t, int n) {
    if (n > t) return n - t;
    if (st[n * 2] >= k) return f(st, k, t, n * 2);
    return f(st, k - st[n * 2], t, n * 2 + 1);
}

int main() {
    int n, a, b, t[1 << 20] = {0};
    scanf("%d", &n);
    int x = 1 << (int) ceil(log2(n));
    for (int i = x; i < x + n; i++) scanf("%d", &t[i]);
    for (int i = x - 1; i >= 1; i--) t[i] = t[i * 2] + t[i * 2 + 1];
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &a, &b);
        if (a == 1) {
            scanf("%d", &a);
            int k = x + b - 1;
            while (k) {
                t[k] += a;
                k /= 2;
            }
        } else printf("%d\n", f(t, b, x - 1, 1));
    }
}
