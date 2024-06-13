#include <stdio.h>
#include <math.h>

int f(int *st, int k, int t, int n) {
    st[n]--;
    if (n > t) return n - t;
    if (st[n * 2] >= k) return f(st, k, t, n * 2);
    return f(st, k - st[n * 2], t, n * 2 + 1);
}

int main() {
    int n, a[1 << 18] = {0}, r[100001], rs[100001];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &r[i]);
    int x = 1 << (int) ceil(log2(n));
    for (int i = x; i < x + n; i++) a[i] = 1;
    for (int i = x - 1; i >= 1; i--) a[i] = a[i * 2] + a[i * 2 + 1];
    for (int i = 1; i <= n; i++) rs[f(a, r[i] + 1, x - 1, 1)] = i;
    for (int i = 1; i <= n; i++) printf("%d\n", rs[i]);
}
