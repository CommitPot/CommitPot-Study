#include <stdio.h>
#include <math.h>

long long tree[1 << 21];

void u(int s, int e, int idx, int r, int n) {
    if (idx < s || idx > e) return;
    tree[n] += r;
    if (s != e) {
        int m = (s + e) / 2;
        u(s, m, idx, r, n * 2);
        u(m + 1, e, idx, r, n * 2 + 1);
    }
}

long long f(int s, int e, int l, int r, int n) {
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return tree[n];
    return f(s, (s + e) / 2, l, r, n * 2) + f((s + e) / 2 + 1, e, l, r, n * 2 + 1);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int x = 1 << (int) ceil(log2(n));
    while (q--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) u(1, x, b, c, 1);
        else printf("%lld\n", f(1, x, b, c, 1));
    }
}
