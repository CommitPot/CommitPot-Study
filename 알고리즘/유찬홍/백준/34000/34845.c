#include <stdio.h>

int main() {
    int n, x, s = 0, r = 0;
    scanf("%d %d", &n, &x);
    for (int i = 0, j; i < n; i++) scanf("%d", &j), s += j;
    while (x * (n + r) > s) s += 100, r++;
    printf("%d", r);
}
