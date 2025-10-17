#include <stdio.h>

int main() {
    int n, p, o, r = 0, w[1001] = {};
    scanf("%d %d", &n, &p);
    o = n;
    while (!w[n]) w[n] = r, n = n * o % p, r++;
    printf("%d", r - w[n]);
}
