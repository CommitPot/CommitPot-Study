#include <stdio.h>

int f(int a, int b) {
    return b ? f(b, a % b) : a;
}

int c[16];

long long g(int *a, int k, long long n, int x, int m) {
    if (x == k) {
        if (!m) return 0;
        long long r = c[0];
        for (int i = 1; i < m; i++) {
            r = (c[i] / f(c[i], r) * r);
            if (r < 0 || r > n) return 0;
        }
        return n / r * (m & 1 ? 1 : -1);
    }
    c[m] = a[x];
    return g(a, k, n, x + 1, m + 1) + g(a, k, n, x + 1, m);
}

int main() {
    int n, k, a[16];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) scanf("%d", &a[i]);
    printf("%lld", n - g(a, k, n, 0, 0));
}
