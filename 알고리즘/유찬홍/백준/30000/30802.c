#include <stdio.h>

int main() {
    int n, a[6], b, c, d = 0;
    scanf("%d", &n);
    for (int i = 0; i < 6; i++) scanf("%d", &a[i]);
    scanf("%d %d", &b, &c);
    for (int i = 0; i < 6; i++) d += a[i] / b + !!(a[i] % b);
    printf("%d\n%d %d", d, n / c, n % c);
}
