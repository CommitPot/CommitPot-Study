#include <stdio.h>

int main() {
    int n, q, c[10001] = {}, r = 0;
    scanf("%d %d", &n, &q);
    for (int i = 0, a, b; i < q; i++) {
        scanf("%d %d", &a, &b);
        while (a <= n) c[a] = 1, a += b;
    }
    for (int i = 1; i <= n; i++) r += c[i];
    printf("%d", n - r);
}
