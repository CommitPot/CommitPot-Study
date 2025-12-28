#include <math.h>
#include <stdio.h>

int t[1 << 19];

int f(int s, int e, int l, int r, int v) {
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return t[v];
    int m = (s + e) / 2;
    return f(s, m, l, r, v * 2) + f(m + 1, e, l, r, v * 2 + 1);
}

void u(int v, int w) {
    while (v) {
        t[v] += w;
        v /= 2;
    }
}

int main() {
    int n, q, a[200002] = {};
    scanf("%d %d", &n, &q);
    int x = pow(2, ceil(log2(n)));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i) t[x + i] = a[i] != a[i - 1];
    }
    for (int i = x - 1; i; i--) t[i] = t[i * 2] + t[i * 2 + 1];
    for (int i = 0, b, c, d; i < q; i++) {
        scanf("%d %d %d", &b, &c, &d);
        if (b == 1) {
            if (a[c - 2] == a[c - 1] && a[c - 1] != d) u(x + c - 1, 1);
            if (a[c - 2] != a[c - 1] && a[c - 2] == d) u(x + c - 1, -1);
            if (c < n) {
                if (a[c - 1] == a[c] && a[c] != d) u(x + c, 1);
                if (a[c - 1] != a[c] && a[c] == d) u(x + c, -1);
            }
            a[c - 1] = d;
        } else printf("%d\n", f(1, x, c + 1, d, 1) + 1);
    }
}
