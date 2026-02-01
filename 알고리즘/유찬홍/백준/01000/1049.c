#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int main() {
    int n, m, r[2] = {1e9, 1e9};
    scanf("%d %d", &n, &m);
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d %d", &a, &b);
        r[0] = min(r[0], min(a, b * 6));
        r[1] = min(r[1], min(a, b));
    }
    printf("%d", n / 6 * r[0] + min(n % 6 * min(r[0], r[1]), r[0]));
}
