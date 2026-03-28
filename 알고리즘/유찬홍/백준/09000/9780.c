#include <stdio.h>

int main() {
    int t, n, q, i, j;
    long long a[100001];
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &q);
        for (i = 1; i <= n; i++) scanf("%lld", &a[i]), a[i] += a[i - 1];
        while (q--) {
            scanf("%d %d", &i, &j);
            printf("%lld\n", a[j + 1] - a[i]);
        }
        printf("\n");
    }
}
