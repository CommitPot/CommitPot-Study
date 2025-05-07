#include <stdio.h>

#define ll long long

void pow(int n, const ll *a, const ll *b, ll *c) {
    ll r[401] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                r[i * n + j] = (r[i * n + j] + a[k * n + j] * b[i * n + k]) % 1000000007;
            }
        }
    }
    for (int i = 0; i < n * n; i++) c[i] = r[i];
}

int main() {
    int t, n, d, m;
    ll p[101][401] = {}, r[401] = {}, rs[401] = {};
    scanf("%d %d %d", &t, &n, &d);
    for (int i = 0; i < n; i++) r[i * n + i] = rs[i * n + i] = 1;
    for (int i = 0; i < t; i++) {
        scanf("%d", &m);
        for (int j = 0, a, b, c; j < m; j++) {
            scanf("%d %d %d", &a, &b, &c);
            p[i][--a * n + --b] = c;
        }
        pow(n, p[i], r, r);
    }
    int s = d / t;
    while (s) {
        if (s & 1) pow(n, r, rs, rs);
        pow(n, r, r, r);
        s /= 2;
    }
    for (int i = 0; i < d % t; i++) {
        pow(n, p[i], rs, rs);
    }
    for (int i = 0; i < n * n; i++) {
        printf("%lld ", rs[i]);
        if (i % n == n - 1) printf("\n");
    }
}
