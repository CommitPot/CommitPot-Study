#include <stdio.h>

#define l(k) for(int k = 0; k < 2; k++)
#define r 1000000

long long (*f(long long (*a)[2], long long w))[2] {
    if (w == 1) return a;
    long long  (*b)[2] = f(a, w / 2);
    long long e[2][2];
    static long long c[2][2] = {};
    l(i) l(j) e[i][j] = b[i][j], c[i][j] = 0;
    l(i) l(j) l(k) c[i][k] = (c[i][k] + e[i][j] * e[j][k]) % r;
    if (!(w & 1)) return c;
    static long long d[2][2] = {};
    l(i) l(j) e[i][j] = c[i][j], d[i][j] = 0;
    l(i) l(j) l(k) d[i][k] = (d[i][k] + e[i][j] * a[j][k]) % r;
    return d;
}

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld", f((long long[2][2]) {0, 1, 1, 1}, n)[1][0]);
}
