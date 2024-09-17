#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int t[1 << 18], x;
bool z[1 << 18];

void lu(int s, int e, int n, int g) {
    if (z[n] || g) {
        int y = x * 2 / (1 << (int) ceil(log2(n + 1)));
        t[n] = (n == 1 ? 4 : y) - t[n];
        if (s != e) {
            z[n * 2] = !z[n * 2];
            z[n * 2 + 1] = !z[n * 2 + 1];
        }
        z[n] = 0;
    }
}

void u(int s, int e, int l, int r, int n) {
    lu(s, e, n, 0);
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        lu(s, e, n, 1);
        return;
    }
    int m = (s + e) / 2;
    u(s, m, l, r, n * 2);
    u(m + 1, e, l, r, n * 2 + 1);
    t[n] = t[n * 2] + t[n * 2 + 1];
}

int f(int s, int e, int l, int r, int n) {
    lu(s, e, n, 0);
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return t[n];
    return f(s, (s + e) / 2, l, r, n * 2) + f((s + e) / 2 + 1, e, l, r, n * 2 + 1);
}

int main() {
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    x = 1 << (int) ceil(log2(n));
    while (m--) {
        scanf("%d %d %d", &a, &b, &c);
        if (a) printf("%d\n", f(1, x, b, c, 1));
        else u(1, x, b, c, 1);
    }
}
