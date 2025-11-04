#include <stdio.h>

int main() {
    int n, k, a[2][100001], b[2];
    long long c[2] = {};
    scanf("%d %d", &n, &k);
    b[0] = b[1] = n - 1;
    for (int i = 0; i < n; i++) scanf("%d", &a[0][i]), c[0] += a[0][i];
    for (int i = 0; i < n; i++) scanf("%d", &a[1][i]), c[1] += a[1][i];
    while (k--) {
        if (c[0] < c[1]) c[1] -= a[1][b[1]--];
        else c[0] -= a[0][b[0]--];
    }
    printf("%lld", c[0] < c[1] ? c[1] : c[0]);
}
