#include <stdio.h>

#define l(k) for(int k = 0; k < 2; k++)
#define u unsigned long long
#define m 1000000007

u (*f(u (*a)[2], u w))[2] {
    if (w == 1) return a;
    u (*b)[2] = f(a, w / 2);
    u e[2][2];
    static u c[2][2] = {};
    l(i) l(j) e[i][j] = b[i][j], c[i][j] = 0;
    l(i) l(j) l(k) c[i][k] = (c[i][k] + e[i][j] * e[j][k]) % m;
    if (w % 2 == 0) return c;
    static u d[2][2] = {};
    l(i) l(j) e[i][j] = c[i][j], d[i][j] = 0;
    l(i) l(j) l(k) d[i][k] = (d[i][k] + e[i][j] * a[j][k]) % m;
    return d;
}

int main() {
    u n;
    scanf("%lld", &n);
    u (*o)[2] = f((u[2][2]) {0, 1, 1, 1}, n);
    printf("%lld", ((o[1][1] * o[1][1] % m - o[1][0] * o[1][0] % m) + (n & 1 ? 1 : -1) + m) % m);
}
