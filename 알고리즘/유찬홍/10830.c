#include <stdio.h>

#define l(l, r, k) for(int k = l; k < r; k++)

int (*f(int (*a)[5], int n, long long w))[5] {
    if (w == 1) return a;
    int (*b)[5] = f(a, n, w / 2);
    int e[5][5];
    static int c[5][5] = {};
    l(0, 5, i) l(0, 5, j) e[i][j] = b[i][j], c[i][j] = 0;
    l(0, n, i) l(0, n, j) l(0, n, k) c[i][k] = (c[i][k] + e[i][j] * e[j][k]) % 1000;
    if (w % 2 == 0) return c;
    static int d[5][5] = {};
    l(0, 5, i) l(0, 5, j) e[i][j] = c[i][j], d[i][j] = 0;
    l(0, n, i) l(0, n, j) l(0, n, k) d[i][k] = (d[i][k] + e[i][j] * a[j][k]) % 1000;
    return d;
}

int main() {
    int n, a[5][5];
    long long m;
    scanf("%d %lld", &n, &m);
    l(0, n, i) l(0, n, j) scanf("%d", &a[i][j]);
    int (*o)[5] = f(a, n, m);
    l(0, n, i) {
        l(0, n, j) printf("%d ", o[i][j] % 1000);
        printf("\n");
    }
}
