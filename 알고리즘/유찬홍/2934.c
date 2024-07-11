#include <stdio.h>

int tree[1 << 18], lazy[1 << 18];

int max(int a, int b) { return a > b ? a : b; }

void lu(int s, int e, int n) {
    if (lazy[n]) {
        tree[n] += lazy[n] * (e - s + 1);
        if (s != e) {
            lazy[n * 2] += lazy[n];
            lazy[n * 2 + 1] += lazy[n];
        }
        lazy[n] = 0;
    }
}

void u(int s, int e, int l, int r, int n) {
    lu(s, e, n);
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        tree[n] += e - s + 1;
        if (s != e) {
            lazy[n * 2]++;
            lazy[n * 2 + 1]++;
        }
        return;
    }
    int m = (s + e) / 2;
    u(s, m, l, r, n * 2);
    u(m + 1, e, l, r, n * 2 + 1);
    tree[n] = max(tree[n * 2], tree[n * 2 + 1]);
}

int f(int s, int e, int t, int n) {
    lu(s, e, n);
    if (e < t || t < s) return 0;
    if (t == s && t == e) return tree[n];
    int m = (s + e) / 2;
    return f(s, m, t, n * 2) + f(m + 1, e, t, n * 2 + 1);
}

int main() {
    int n, a, b, x = 131072;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", f(1, x, a, 1) + f(1, x, b, 1));
        tree[x + a - 1] = tree[x + b - 1] = 0;
        u(1, x, a + 1, b - 1, 1);
    }
}
