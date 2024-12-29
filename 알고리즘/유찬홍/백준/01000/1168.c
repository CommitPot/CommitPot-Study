#include <stdio.h>
#include <math.h>

int f(int *st, int k, int t, int n) {
    st[n]--;
    if (n >= t) return n - t;
    if (st[n * 2] >= k) return f(st, k, t, n * 2);
    return f(st, k - st[n * 2], t, n * 2 + 1);
}

int main() {
    int n, k, a[1 << 18] = {0};
    scanf("%d %d", &n, &k);
    int x = 1 << (int) ceil(log2(n));
    for (int i = x; i < x + n; i++) a[i] = 1;
    for (int i = x + n; i > 1; i--) a[i / 2] += a[i];
    int r = k;
    printf("<");
    while (a[1] > 1) {
        printf("%d, ", f(a, r, x, 1) % n + 1);
        r = (r + k - 2) % a[1] + 1;
    }
    printf("%d>", f(a, 1, x, 1) % n + 1);
}
