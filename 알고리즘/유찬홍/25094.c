#include <stdio.h>

int main() {
    int n, m, i = 0, r = 0, a[100];
    scanf("%d %d", &n, &m);
    for (; i < n; i++) scanf("%d", &a[i]);
    while (m++ <= a[r++ % n]);
    printf("%d", --r % n + 1);
}
